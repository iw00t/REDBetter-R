#ifndef API_VIEW
#define API_VIEW

#include "BaseView.h"
#include "APIViewInterface.h"

namespace REDBetterR {
    namespace API {
        class APIView : public BaseView, public APIViewInterface {
        public:
            void displayLoginWithCookie() const;
            void displayLoginWithUsernamePassword() const;
            void displayLoginSuccessful() const;
            void displayLoginFailed() const;
        };
    }
}

#endif // API_VIEW