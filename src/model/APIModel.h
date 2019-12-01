#ifndef API_MODEL
#define API_MODEL

#include "BaseModel.h"
#include "APIModelInterface.h"

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        class APIModel : public BaseModel, public APIModelInterface {
        public:
            APIModel(Common::CprHelperInterface & cprHelper, Common::JsonHelperInterface & jsonHelper);
            bool sessionCookieSet(const std::map<std::string, std::string> & config);
            bool loginCookie(const std::map<std::string, std::string> & config);
            bool loginUsernamePassword(const std::map<std::string, std::string> & config);
            nlohmann::json getUserInfo() const;

            std::string getAuthkey() const;
            void setAuthkey(const std::string & authkey);
            std::string getPasskey() const;
            void setPasskey(const std::string & passkey);
            unsigned int getUserId() const;
            void setUserId(unsigned int userId);

        private:
            std::string authkey;
            std::string passkey;
            unsigned int userId = 0;
            nlohmann::json request(const std::string & action) const;
        };
    }
}

#endif //API_MODEL
