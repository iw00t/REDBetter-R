#include "APIModel.h"

#include "../constants/APIConstants.h"

#include <fstream>

namespace REDBetterR {
    namespace API {
        APIModel::APIModel() {
            this->session->SetVerifySsl(false);
            this->session->SetHeader({
                {"Connection", "keep-alive"},
                {"Cache-Control", "max-age=0"},
                {"User-Agent", "REDBetter-R"},
                {"Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"},
                {"Accept-Encoding", "gzip,deflate,sdch"},
                {"Accept-Language", "en-US,en;q=0.8"},
                {"Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.3"}
            });
        }

        bool APIModel::sessionCookieSet(const std::map<std::string, std::string> & config) {
            return config.at(Constants::Field::SESSION_COOKIE) != "";
        }

        bool APIModel::loginCookie(const std::map<std::string, std::string> & config) {
            this->session->SetUrl(Constants::URL::BASE);
            this->session->SetHeader({
                {Constants::Header::SESSION_COOKIE, Constants::Field::SESSION + "=" + config.at(Constants::Field::SESSION_COOKIE)}
            });
            auto loginGet = this->session->Get();
            try {
                nlohmann::json accountInfo = this->request(Constants::Action::INDEX);
                this->authkey = *accountInfo.find(Constants::Field::AUTHKEY);
                this->passkey = *accountInfo.find(Constants::Field::PASSKEY);
                this->userId = *accountInfo.find(Constants::Field::ID);
                return true;
            } catch (const nlohmann::detail::parse_error & e) {
                return false;
            }
        }

        bool APIModel::loginUsernamePassword(const std::map<std::string, std::string> & config) {
            this->session->SetUrl(Constants::URL::LOGIN);
            this->session->SetPayload({
                {Constants::Field::USERNAME, config.at(Constants::Field::USERNAME)},
                {Constants::Field::PASSWORD, config.at(Constants::Field::PASSWORD)}
            });
            auto loginPost = this->session->Post();
            try {
                nlohmann::json accountInfo = this->request(Constants::Action::INDEX);
                this->authkey = *accountInfo.find(Constants::Field::AUTHKEY);
                this->passkey = *accountInfo.find(Constants::Field::PASSKEY);
                this->userId = *accountInfo.find(Constants::Field::ID);
                return true;
            } catch (const nlohmann::detail::parse_error & e) {
                return false;
            }
        }

        nlohmann::json APIModel::getUserInfo() const {
            return this->request(Constants::Action::INDEX);
        }

        nlohmann::json APIModel::request(const std::string & action) const {
            cpr::Parameters requestGetParameters;
            requestGetParameters.AddParameter(cpr::Parameter(Constants::Parameter::ACTION, action));
            if (!this->authkey.empty()) {
                requestGetParameters.AddParameter(cpr::Parameter(Constants::Parameter::AUTH, this->authkey));
            }
            this->session->SetUrl(Constants::URL::AJAX);
            this->session->SetParameters(requestGetParameters);
            auto requestGet = this->session->Get();
            try {
                nlohmann::json responseJson = nlohmann::json::parse(requestGet.text);
                if (*responseJson.find(Constants::Field::STATUS) == Constants::Response::SUCCESS) {
                    return *responseJson.find(Constants::Field::RESPONSE);
                }
            } catch (nlohmann::json::parse_error & e) {
				// TODO: Throw exception.
			}
            return "";
        }
    }
}
