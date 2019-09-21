#ifndef API_MODEL
#define API_MODEL

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        class APIModel {
        public:
            APIModel(std::map<std::string, std::string> & config);
            APIModel() {}
            ~APIModel() {}
            bool sessionCookieSet();
            void loginCookie();
            void loginUsernamePassword();

        private:
            std::map<std::string, std::string> config;
        };
    }
}

#endif //API_MODEL
