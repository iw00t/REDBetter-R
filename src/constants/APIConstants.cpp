#ifndef API_CONSTANTS
#define API_CONSTANTS

#include <string>

namespace REDBetterR {
    namespace API {
        namespace Constants {
            const std::string USERNAME_FIELD = "username";
            const std::string PASSWORD_FIELD = "password";
            const std::string SESSION_FIELD = "session";
            const std::string COOKIE_HEADER_FIELD = "Cookie";
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
            const std::string USER_STATS_FIELD = "userstats";
            const std::string CLASS_FIELD = "class";
            const std::string UPLOADED_FIELD = "uploaded";
            const std::string DOWNLOADED_FIELD = "downloaded";
            const std::string RATIO_FIELD = "ratio";
            const std::string REQUIRED_RATIO_FIELD = "requiredratio";
            const std::string OUTPUT_SPACER = " : ";
            const int OUTPUT_SPACING = 14;
        }
    }
}

#endif //API_CONSTANTS
