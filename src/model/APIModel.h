#ifndef API_MODEL
#define API_MODEL

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        const std::string USERNAME_FIELD = "username";
        const std::string PASSWORD_FIELD = "password";
        const std::string LOG_IN_FORM_URL = "https://redacted.ch/login.php";
        const std::string LOGGED_IN_URL = "https://redacted.ch/index.php";

        class APIModel {
        public:
            APIModel(std::map<std::string, std::string> & config);
            APIModel() {}
            ~APIModel() {}
            bool sessionCookieSet();
            void loginCookie();
            bool loginUsernamePassword();

        private:
            std::map<std::string, std::string> config;
        };
    }
}

#endif //API_MODEL
