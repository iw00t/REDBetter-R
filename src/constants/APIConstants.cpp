#ifndef API_CONSTANTS
#define API_CONSTANTS

#include <string>

namespace REDBetterR {
    namespace API {
        namespace Constants {
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
            const std::string SESSION_COOKIE_FIELD = "session_cookie";
        }
    }
}

#endif //API_CONSTANTS
