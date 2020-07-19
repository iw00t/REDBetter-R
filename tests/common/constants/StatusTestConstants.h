#ifndef STATUS_TEST_CONSTANTS
#define STATUS_TEST_CONSTANTS

#include <string>
#include <unordered_map>


namespace REDBetterR {
    namespace StatusTest {
        namespace Constants {
            const std::string NAME = "status";

            class URL {
            public:
                static const std::string RED_TRACKER_STATUS_ALL;
            };

            class JSON {
            public:
                static const std::unordered_map<std::string, std::string> SERVICES;
                static const std::string STATUS;
                static const std::string LATENCY;
            };

            class Online {
            public:
                static const std::string OFFLINE_STATUS_VALUE;
                static const std::string OFFLINE_STATUS_DISPLAY;
                static const std::string ONLINE_STATUS_VALUE;
                static const std::string ONLINE_STATUS_DISPLAY;
                static const std::string UNSTABLE_STATUS_VALUE;
                static const std::string UNSTABLE_STATUS_DISPLAY;
                static const std::string UNKNOWN_STATUS_DISPLAY;
            };

            class Output {
            public:
                static const int SPACING;
            };
        }
    }
}

#endif // STATUS_TEST_CONSTANTS
