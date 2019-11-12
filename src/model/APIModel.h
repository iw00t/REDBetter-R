#ifndef API_MODEL
#define API_MODEL

#include "BaseModel.h"

#include <cpr/cpr.h>
#include "../../opt/json.hpp"

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        class APIModel : public BaseModel {
        public:
            APIModel(std::map<std::string, std::string> & config);
            bool sessionCookieSet();
            bool loginCookie();
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
