#include "APIConstants.h"


namespace REDBetterR {
    namespace API {
        namespace Constants {
            const std::string URL::BASE = "https://redacted.ch/";
            const std::string URL::LOGIN = URL::BASE + "login.php";
            const std::string URL::AJAX = URL::BASE + "ajax.php";

            const std::string Field::USERNAME = "username";
            const std::string Field::PASSWORD = "password";
            const std::string Field::SESSION = "session";
            const std::string Field::RESPONSE = "response";
            const std::string Field::AUTHKEY = "authkey";
            const std::string Field::PASSKEY = "passkey";
            const std::string Field::SESSION_COOKIE = "session_cookie";
            const std::string Field::USER_STATS = "userstats";
            const std::string Field::CLASS = "class";
            const std::string Field::UPLOADED = "uploaded";
            const std::string Field::DOWNLOADED = "downloaded";
            const std::string Field::RATIO = "ratio";
            const std::string Field::REQUIRED_RATIO = "requiredratio";
            const std::string Field::STATUS = "status";
            const std::string Field::ID = "id";

            const std::string Header::SESSION_COOKIE = "Cookie";

            const std::string Response::SUCCESS = "success";

            const std::string Parameter::ACTION = "action";
            const std::string Parameter::AUTH = "auth";

            const std::string Action::INDEX = "index";
            
            const std::string Output::SPACER = " : ";
            const int Output::SPACING = 14;
        }
    }
}
