#ifndef API_MODEL_INTERFACE
#define API_MODEL_INTERFACE

#include "BaseModelInterface.h"
#include "../vo/ReleaseVO.h"

#include "../../opt/json.hpp"
#include <string>
#include <map>


namespace REDBetterR {
    namespace API {
        class APIModelInterface : public BaseModelInterface {
        public:
            ~APIModelInterface() override = default;
            virtual bool sessionCookieSet(const std::map<std::string, std::string> &) = 0;
            virtual bool loginCookie(const std::map<std::string, std::string> &) = 0;
            virtual bool loginUsernamePassword(const std::map<std::string, std::string> &) = 0;
            virtual nlohmann::json getUserInfo() = 0;
            virtual std::map<std::string, std::string> getSnatched() = 0;
            virtual VO::ReleaseVO getReleaseInfo(const std::pair<std::string, std::string> &) = 0;
        };
    }
}

#endif //API_MODEL_INTERFACE
