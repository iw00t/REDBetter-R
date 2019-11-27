#ifndef API_MODEL
#define API_MODEL

#include "BaseModel.h"
#include "APIModelInterface.h"

#include <cpr/cpr.h>

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        class APIModel : public BaseModel, public APIModelInterface {
        public:
            APIModel();
            bool sessionCookieSet(const std::map<std::string, std::string> & config);
            bool loginCookie(const std::map<std::string, std::string> & config);
            bool loginUsernamePassword(const std::map<std::string, std::string> & config);
            nlohmann::json getUserInfo() const;

        private:
            cpr::Session* session = new cpr::Session();
            std::string authkey;
            std::string passkey;
            unsigned int userId;
            nlohmann::json request(const std::string & action) const;
        };
    }
}

#endif //API_MODEL
