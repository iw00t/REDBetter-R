#include "APIModel.h"

#include "../common/constants/CommonConstants.h"
#include "../common/constants/APIConstants.h"

#include <ctime>
#include <fstream>
#include <regex>
#include <iostream>

namespace REDBetterR {
    namespace API {
        APIModel::APIModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper, std::shared_ptr<Common::JsonHelperInterface> & jsonHelper) : BaseModel(cprHelper, jsonHelper) {
            this->getCprHelper()->setHeader(Constants::Metadata::HEADER);
        }

        bool APIModel::sessionCookieSet(const std::map<std::string, std::string> & config) {
            return config.at(Constants::Field::SESSION_COOKIE) != "";
        }

        bool APIModel::loginCookie(const std::map<std::string, std::string> & config) {
            if (!config.empty()) {
                std::string sessionCookie;
                if (config.count(Constants::Field::SESSION_COOKIE) > 0) {
                    sessionCookie = config.at(Constants::Field::SESSION_COOKIE);
                }
                if (!sessionCookie.empty()) {
                    this->getCprHelper()->setUrl(Constants::URL::BASE);
                    this->getCprHelper()->setHeader({{
                        Constants::Header::SESSION_COOKIE,
                        Constants::Field::SESSION + "=" + config.at(Constants::Field::SESSION_COOKIE)
                    }});
                    this->getCprHelper()->get();
                    try {
                        nlohmann::json accountInfo = this->getUserInfo();
                        if (!accountInfo.empty()) {
                            this->setAuthkey(*accountInfo.find(Constants::Field::AUTHKEY));
                            this->setPasskey(*accountInfo.find(Constants::Field::PASSKEY));
                            this->setUserId(*accountInfo.find(Constants::Field::ID));
                            return true;
                        }
                    } catch (const nlohmann::detail::parse_error & e) {
                        // TODO: Logging
                    }
                }
            }
            return false;
        }

        bool APIModel::loginUsernamePassword(const std::map<std::string, std::string> & config) {
            if (!config.empty()) {
                std::string username;
                std::string password;
                if (config.count(Constants::Field::USERNAME) > 0 && config.count(Constants::Field::PASSWORD) > 0) {
                    username = config.at(Constants::Field::USERNAME);
                    password = config.at(Constants::Field::PASSWORD);
                }
                if (!username.empty() && !password.empty()) {
                    this->getCprHelper()->setUrl(Constants::URL::LOGIN);
                    this->getCprHelper()->setPayload({
                        {Constants::Field::USERNAME, config.at(Constants::Field::USERNAME)},
                        {Constants::Field::PASSWORD, config.at(Constants::Field::PASSWORD)}
                    });
                    this->getCprHelper()->post();
                    try {
                        nlohmann::json accountInfo = this->getUserInfo();
                        if (!accountInfo.empty()) {
                            this->authkey = *accountInfo.find(Constants::Field::AUTHKEY);
                            this->passkey = *accountInfo.find(Constants::Field::PASSKEY);
                            this->userId = *accountInfo.find(Constants::Field::ID);
                            return true;
                        }
                    } catch (const nlohmann::detail::parse_error & e) {
                        // TODO: Logging
                    }
                }
            }
            return false;
        }

        nlohmann::json APIModel::getUserInfo() {
            return this->doAPIRequest(Constants::Action::INDEX);
        }

        std::map<std::string, std::string> APIModel::getSnatched() {
            std::map<std::string, std::string> snatchedTorrents = std::map<std::string, std::string>();

            bool reachedEnd = false;
            int pageNum = 1;
            while (!reachedEnd) {
                std::map<std::string, std::string> getSnatchedParameters;
                getSnatchedParameters.insert({Constants::Parameter::TYPE, Constants::Parameter::SNATCHED});
                getSnatchedParameters.insert({Constants::Parameter::USERID, std::to_string(this->userId)});
                getSnatchedParameters.insert({Constants::Parameter::FORMAT, Constants::Parameter::FLAC});
                getSnatchedParameters.insert({Constants::Parameter::PAGE, std::to_string(pageNum)});
                std::string snatchedPageContent = this->doHTMLRequest(Constants::URL::TORRENTS, getSnatchedParameters);

                std::regex expression("torrents\\.php\\?id=(\\d+)&amp;torrentid=(\\d+)");
                std::smatch match;
                while(std::regex_search(snatchedPageContent, match, expression)) {
                    snatchedTorrents.insert(std::pair<std::string, std::string>(match[1], match[2]));
                    snatchedPageContent = match.suffix();
                }

                if (snatchedPageContent.find("Next &gt;") == std::string::npos) {
                    reachedEnd = true;
                }
                pageNum += 1;
            }

            return snatchedTorrents;
        }

        VO::ReleaseVO APIModel::getReleaseInfo(const std::pair<std::string, std::string> & snatchedTorrent) {
            std::string groupId = snatchedTorrent.first;
            std::string torrentId = snatchedTorrent.second;
            nlohmann::json groupInfoJson = this->getGroupInfo(groupId);

            if (!groupInfoJson.empty()) {
                nlohmann::json torrentInfoJson = this->getTorrentInfo(groupInfoJson);

                std::string releaseArtist = this->getArtist(groupInfoJson["group"]["musicInfo"]["artists"]);
                std::string releaseName = groupInfoJson["group"]["name"].dump();
                std::string releaseYear = this->getYear(torrentInfoJson["remasterYear"].dump(), groupInfoJson["group"]["year"].dump());
                std::string releaseUrl = "https://redacted.ch/torrents.php?id=" + groupId + "&torrentid=" + torrentId + "#torrent" + torrentId;
                std::string media = torrentInfoJson["media"].dump();
                std::string filePath = torrentInfoJson["filePath"].dump();
                std::string fileList = torrentInfoJson["fileList"].dump();
                std::string encoding = torrentInfoJson["encoding"].dump();
                std::string remasterTitle = torrentInfoJson["remasterTitle"].dump();
                std::string remasterYear = torrentInfoJson["remasterYear"].dump();
                std::string remasterRecordLabel = torrentInfoJson["remasterRecordLabel"].dump();
                std::string remasterCatalogueNumber = torrentInfoJson["remasterCatalogueNumber"].dump();

                std::vector<std::string> existingFormats = std::vector<std::string>();
                for (const auto & torrent : groupInfoJson["torrents"]) {
                    existingFormats.push_back(torrent['format']);
                }

                std::vector<std::string> missingFormats = std::vector<std::string>();
                for (const auto & format : Common::Constants::FORMATS) {
                    std::string formatStr = format.first;
                    if (std::find(existingFormats.begin(), existingFormats.end(), formatStr) != existingFormats.end()){ 
                        missingFormats.push_back(formatStr);
                    }
                }
                //missingFormats.push_back()

                VO::ReleaseVO releaseInfo = VO::ReleaseVO::builder().id(groupId)
                                                                    .releaseArtist(releaseArtist)
                                                                    .releaseName(releaseName)
                                                                    .releaseYear(releaseYear)
                                                                    .releaseUrl(releaseUrl)
                                                                    .media(media)
                                                                    .filePath(filePath)
                                                                    .fileList(fileList)
                                                                    .encoding(encoding)
                                                                    .remasterTitle(remasterTitle)
                                                                    .remasterYear(remasterYear)
                                                                    .remasterRecordLabel(remasterRecordLabel)
                                                                    .remasterCatalogueNumber(remasterCatalogueNumber)
                                                                    .build();
                return releaseInfo;
            }
            return VO::ReleaseVO();
        }

        std::string APIModel::getAuthkey() const {
            return this->authkey;
        }

        void APIModel::setAuthkey(const std::string & authkey) {
            this->authkey = authkey;
        }

        std::string APIModel::getPasskey() const {
            return this->passkey;
        }

        void APIModel::setPasskey(const std::string & passkey) {
            this->passkey = passkey;
        }

        unsigned int APIModel::getUserId() const {
            return this->userId;
        }

        void APIModel::setUserId(unsigned int userId) {
            this->userId = userId;
        }

        nlohmann::json APIModel::getGroupInfo(const std::string & groupId) {
            std::map<std::string, std::string> getGroupInfoParameters;
            getGroupInfoParameters.insert({Constants::Parameter::GROUP_ID, groupId});
            return this->doAPIRequest(Constants::Action::TORRENT_GROUP, getGroupInfoParameters);
        }

        nlohmann::json APIModel::getTorrentInfo(const nlohmann::json & groupInfo) const {
            for (const auto torrentInfo : groupInfo["torrents"]) {
                if (!torrentInfo["id"].empty()) {
                    return torrentInfo;
                }
            }
            return nullptr;
        }

        std::string APIModel::getArtist(const nlohmann::json & artistsArray) const {
            if (artistsArray.size() > 1) {
                return "Various Artists";
            }
            return artistsArray[0]["name"];
        }

        std::string APIModel::getYear(const std::string & remasterYear, const std::string & groupYear) const {
            if (remasterYear.empty() || remasterYear == "0") {
                return groupYear;
            }
            return remasterYear;
        }

        nlohmann::json APIModel::doAPIRequest(const std::string & action, const std::map<std::string, std::string> & additionalParameters) {
            std::map<std::string, std::string> requestGetParameters;
            requestGetParameters.insert({Constants::Parameter::ACTION, action});
            if (!this->authkey.empty()) {
                requestGetParameters.insert({Constants::Parameter::AUTH, this->authkey});
            }
            requestGetParameters.insert(additionalParameters.begin(), additionalParameters.end());
            this->getCprHelper()->setParameters(requestGetParameters);
            this->getCprHelper()->setUrl(Constants::URL::AJAX);
            auto requestGet = this->getCprHelper()->get();
            try {
                nlohmann::json responseJson = this->getJsonHelper()->parse(requestGet.text);
                if (!responseJson.is_null() && !responseJson.empty() && *responseJson.find(Constants::Field::STATUS) == Constants::Response::SUCCESS) {
                    return *responseJson.find(Constants::Field::RESPONSE);
                }
            } catch (nlohmann::json::parse_error & e) {
                // TODO: Throw exception.
            }
            return {};
        }

        std::string APIModel::doHTMLRequest(const std::string & url, const std::map<std::string, std::string> & parameters) {
            this->getCprHelper()->setParameters(parameters);
            this->getCprHelper()->setUrl(url);
            auto requestGet = this->getCprHelper()->get();
            return requestGet.text;
        }
    }
}
