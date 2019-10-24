#ifndef API_VIEW
#define API_VIEW

namespace REDBetterR {
    namespace API {
        class APIView {
        public:
            APIView() {}
            ~APIView() {}
            void displayLoginWithCookie();
            void displayLoginWithUsernamePassword();
            void displayLoginSuccessful();
            void displayLoginFailed();
        };
    }
}

#endif // API_VIEW