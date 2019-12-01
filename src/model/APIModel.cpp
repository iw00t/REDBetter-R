#include "APIModel.h"

#include "../constants/APIConstants.h"

#include <fstream>

namespace REDBetterR {
    namespace API {
        APIModel::APIModel(Common::CprHelperInterface & cprHelper, Common::JsonHelperInterface & jsonHelper) : BaseModel(cprHelper, jsonHelper) {
            this->getCprHelper()->setVerifySsl(Constants::Metadata::VERIFY_SSL);
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

        nlohmann::json APIModel::getUserInfo() const {
            return this->request(Constants::Action::INDEX);
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

        nlohmann::json APIModel::request(const std::string & action) const {
            std::map<std::string, std::string> requestGetParameters;
            requestGetParameters.insert({Constants::Parameter::ACTION, action});
            if (!this->authkey.empty()) {
                requestGetParameters.insert({Constants::Parameter::AUTH, this->authkey});
            }
            this->getCprHelper()->setUrl(Constants::URL::AJAX);
            this->getCprHelper()->setParameters(requestGetParameters);
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
    }
}
