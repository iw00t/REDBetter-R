#include "APIModel.h"

#include <map>
#include <iostream>
#include <fstream>

namespace REDBetterR {
    namespace API {
        APIModel::APIModel(std::map<std::string, std::string> & config) {
            this->config = config;
        }

        bool APIModel::sessionCookieSet() {
            return this->config.at("session_cookie") != "";
        }

        void APIModel::loginCookie() {
            // TODO: Login mechanism when using session cookie.
        }

        bool APIModel::loginUsernamePassword() {
            this->session->SetUrl(LOGIN_URL);
            this->session->SetPayload({
                {USERNAME_FIELD, this->config.at(USERNAME_FIELD)},
                {PASSWORD_FIELD, this->config.at(PASSWORD_FIELD)}
            });
            auto loginPost = this->session->Post();
            if (loginPost.url == HOME_URL) {
                nlohmann::json accountInfo = this->request(INDEX_ACTION);
                this->authkey = *accountInfo.find(AUTHKEY_FIELD);
                this->passkey = *accountInfo.find(PASSKEY_FIELD);
                this->userId = *accountInfo.find(ID_FIELD);
            } else {
                // TODO: Logic for a failed login.
            }
        }

        nlohmann::json APIModel::request(const std::string & action) {
            cpr::Parameters requestGetParameters;
            requestGetParameters.AddParameter(cpr::Parameter(ACTION_PARAMETER, action));
            if (!this->authkey.empty()) {
                requestGetParameters.AddParameter(cpr::Parameter(AUTH_PARAMETER, this->authkey));
            }
            this->session->SetUrl(AJAX_URL);
            this->session->SetParameters(requestGetParameters);
            auto requestGet = this->session->Get();
            nlohmann::json responseJson = nlohmann::json::parse(requestGet.text);
            if (*responseJson.find(STATUS_FIELD) == SUCCESS_RESPONSE) {
                return *responseJson.find(RESPONSE_FIELD);
            }
            // TODO: Handle bad request.
            return "";
        }
    }
}
