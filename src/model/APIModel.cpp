#include "APIModel.h"

#include "../constants/APIConstants.cpp"

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
            return config.at(Constants::SESSION_COOKIE_FIELD) != "";
        }

        bool APIModel::loginCookie(const std::map<std::string, std::string> & config) {
            this->session->SetUrl(Constants::BASE_URL);
            this->session->SetHeader({
                {Constants::COOKIE_HEADER_FIELD, Constants::SESSION_FIELD + "=" + config.at(Constants::SESSION_COOKIE_FIELD)}
            });
            auto loginGet = this->session->Get();
            try {
                nlohmann::json accountInfo = this->request(Constants::INDEX_ACTION);
                this->authkey = *accountInfo.find(Constants::AUTHKEY_FIELD);
                this->passkey = *accountInfo.find(Constants::PASSKEY_FIELD);
                this->userId = *accountInfo.find(Constants::ID_FIELD);
                return true;
            } catch (const nlohmann::detail::parse_error & e) {
                return false;
            }
        }

        bool APIModel::loginUsernamePassword(const std::map<std::string, std::string> & config) {
            this->session->SetUrl(Constants::LOGIN_URL);
            this->session->SetPayload({
                {Constants::USERNAME_FIELD, config.at(Constants::USERNAME_FIELD)},
                {Constants::PASSWORD_FIELD, config.at(Constants::PASSWORD_FIELD)}
            });
            auto loginPost = this->session->Post();
            try {
                nlohmann::json accountInfo = this->request(Constants::INDEX_ACTION);
                this->authkey = *accountInfo.find(Constants::AUTHKEY_FIELD);
                this->passkey = *accountInfo.find(Constants::PASSKEY_FIELD);
                this->userId = *accountInfo.find(Constants::ID_FIELD);
                return true;
            } catch (const nlohmann::detail::parse_error & e) {
                return false;
            }
        }

        nlohmann::json APIModel::getUserInfo() const {
            return this->request(Constants::INDEX_ACTION);
        }

        nlohmann::json APIModel::request(const std::string & action) const {
            cpr::Parameters requestGetParameters;
            requestGetParameters.AddParameter(cpr::Parameter(Constants::ACTION_PARAMETER, action));
            if (!this->authkey.empty()) {
                requestGetParameters.AddParameter(cpr::Parameter(Constants::AUTH_PARAMETER, this->authkey));
            }
            this->session->SetUrl(Constants::AJAX_URL);
            this->session->SetParameters(requestGetParameters);
            auto requestGet = this->session->Get();
            try {
                nlohmann::json responseJson = nlohmann::json::parse(requestGet.text);
                if (*responseJson.find(Constants::STATUS_FIELD) == Constants::SUCCESS_RESPONSE) {
                    return *responseJson.find(Constants::RESPONSE_FIELD);
                }
            } catch (nlohmann::json::parse_error & e) {
				// TODO: Throw exception.
			}
            return "";
        }
    }
}
