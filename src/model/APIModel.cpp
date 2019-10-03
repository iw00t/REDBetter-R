#include "APIModel.h"

#include <cpr/cpr.h>

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

        bool APIModel::loginUsernamePassword() {;
            auto loginPost = cpr::Post(cpr::Url{LOG_IN_FORM_URL},
            cpr::Payload{
                {USERNAME_FIELD, this->config.at(USERNAME_FIELD)},
                {PASSWORD_FIELD, this->config.at(PASSWORD_FIELD)}
            });

            if (loginPost.url == LOGGED_IN_URL) {
                // TODO: Logic for a successful login.
            } else {
                // TODO: Logic for a failed login.
            }
        }
    }
}
