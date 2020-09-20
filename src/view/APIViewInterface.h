#ifndef API_VIEW_INTERFACE
#define API_VIEW_INTERFACE

#include "BaseViewInterface.h"

#include "../../opt/json.hpp"
#include <string>
#include <vector>
#include <map>


namespace REDBetterR {
    namespace API {
        class APIViewInterface : public BaseViewInterface {
        public:
            ~APIViewInterface() override = default;
            virtual void displayLoginWithCookie() const = 0;
            virtual void displayLoginWithUsernamePassword() const = 0;
            virtual void displayLoginSuccessful() const = 0;
            virtual void displayLoginFailed() const = 0;
            virtual void displayUserInfo(const nlohmann::json &) const = 0;
            virtual void displayObtainingSnatchedTorrents() const = 0;
            virtual void displayObtainingTranscodeCandidates(int current, int total) const = 0;
        };
    }
}

#endif // API_VIEW_INTERFACE