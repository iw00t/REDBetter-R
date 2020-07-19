#ifndef API_TEST_CONSTANTS
#define API_TEST_CONSTANTS

#include <string>
#include <map>


namespace REDBetterR {
    namespace APITest {
        namespace Constants {
            const std::string NAME = "api";

            class Metadata {
            public:
                static const bool VERIFY_SSL;
                static const std::map<std::string, std::string> HEADER;
            };

            class URL {
            public:
                static const std::string BASE;
                static const std::string LOGIN;
                static const std::string AJAX;
            };

            class Field {
            public:
                static const std::string USERNAME;
                static const std::string PASSWORD;
                static const std::string SESSION;
                static const std::string RESPONSE;
                static const std::string AUTHKEY;
                static const std::string PASSKEY;
                static const std::string SESSION_COOKIE;
                static const std::string USER_STATS;
                static const std::string CLASS;
                static const std::string UPLOADED;
                static const std::string DOWNLOADED;
                static const std::string RATIO;
                static const std::string REQUIRED_RATIO;
                static const std::string STATUS;
                static const std::string ID;
            };

            class Header {
            public:
                static const std::string SESSION_COOKIE;
            };

            class Response {
            public:
                static const std::string SUCCESS;
            };

            class Parameter {
            public:
                static const std::string ACTION;
                static const std::string AUTH;
            };

            class Action {
            public:
                static const std::string INDEX;
            };

            class Output {
            public:
                static const std::string SPACER;
                static const int SPACING;
            };
        }
    }
}

#endif // API_TEST_CONSTANTS
