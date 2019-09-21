#include "APIModel.h"

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

        void APIModel::loginUsernamePassword() {
            // TODO: Login mechanism when using username and password.
        }
    }
}
