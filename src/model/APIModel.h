#ifndef API_MODEL
#define API_MODEL

#include <cpr/cpr.h>
#include "../../opt/json.hpp"

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        const std::string USERNAME_FIELD = "username";
        const std::string PASSWORD_FIELD = "password";
        const std::string BASE_URL = "https://redacted.ch/";
        const std::string LOGIN_URL = BASE_URL + "login.php";
        const std::string HOME_URL = BASE_URL + "index.php";
        const std::string AJAX_URL = BASE_URL + "ajax.php";
        const std::string ACTION_PARAMETER = "action";
        const std::string AUTH_PARAMETER = "auth";
        const std::string INDEX_ACTION = "index";
        const std::string STATUS_FIELD = "status";
        const std::string SUCCESS_RESPONSE = "success";
        const std::string RESPONSE_FIELD = "response";
        const std::string AUTHKEY_FIELD = "authkey";
        const std::string PASSKEY_FIELD = "passkey";
        const std::string ID_FIELD = "id";

        class APIModel {
        public:
            APIModel(std::map<std::string, std::string> & config);
            APIModel() {}
            ~APIModel() {}
            bool sessionCookieSet();
            void loginCookie();
            bool loginUsernamePassword();

        private:
            cpr::Session* session = new cpr::Session();
            std::map<std::string, std::string> config;
            std::string authkey;
            std::string passkey;
            unsigned int userId;
            nlohmann::json request(const std::string & action);
        };
    }
}

#endif //API_MODEL
