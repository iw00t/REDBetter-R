#ifndef API_VIEW
#define API_VIEW

#include "BaseView.h"

namespace REDBetterR {
    namespace API {
        class APIView : public BaseView {
        public:
            void displayLoginWithCookie();
            void displayLoginWithUsernamePassword();
            void displayLoginSuccessful();
            void displayLoginFailed();
        };
    }
}

#endif // API_VIEW