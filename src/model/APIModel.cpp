#include "APIModel.h"

#include "../constants/APIConstants.cpp"

#include <map>
#include <iostream>
#include <fstream>

namespace REDBetterR {
    namespace API {
        APIModel::APIModel(std::map<std::string, std::string> & config) {
            this->config = config;
        }

        bool APIModel::sessionCookieSet() {
            return this->config.at(Constants::SESSION_COOKIE_FIELD) != "";
        }

        void APIModel::loginCookie() {
            // TODO: Login mechanism when using session cookie.
        }

        bool APIModel::loginUsernamePassword() {
            this->session->SetUrl(Constants::LOGIN_URL);
            this->session->SetPayload({
                {Constants::USERNAME_FIELD, this->config.at(Constants::USERNAME_FIELD)},
                {Constants::PASSWORD_FIELD, this->config.at(Constants::PASSWORD_FIELD)}
            });
            auto loginPost = this->session->Post();
            if (loginPost.url == Constants::HOME_URL) {
                nlohmann::json accountInfo = this->request(Constants::INDEX_ACTION);
                this->authkey = *accountInfo.find(Constants::AUTHKEY_FIELD);
                this->passkey = *accountInfo.find(Constants::PASSKEY_FIELD);
                this->userId = *accountInfo.find(Constants::ID_FIELD);
            } else {
                // TODO: Logic for a failed login.
            }
        }

        nlohmann::json APIModel::request(const std::string & action) {
            cpr::Parameters requestGetParameters;
            requestGetParameters.AddParameter(cpr::Parameter(Constants::ACTION_PARAMETER, action));
            if (!this->authkey.empty()) {
                requestGetParameters.AddParameter(cpr::Parameter(Constants::AUTH_PARAMETER, this->authkey));
            }
            this->session->SetUrl(Constants::AJAX_URL);
            this->session->SetParameters(requestGetParameters);
            auto requestGet = this->session->Get();
            nlohmann::json responseJson = nlohmann::json::parse(requestGet.text);
            if (*responseJson.find(Constants::STATUS_FIELD) == Constants::SUCCESS_RESPONSE) {
                return *responseJson.find(Constants::RESPONSE_FIELD);
            }
            // TODO: Handle bad request.
            return "";
        }
    }
}
