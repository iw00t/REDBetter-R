#ifndef STATUS_CONSTANTS
#define STATUS_CONSTANTS

#include <string>
#include <unordered_map>


namespace REDBetterR {
    namespace Status {
        namespace Constants {
            const std::string NAME = "status";

            class Metadata {
            public:
                static const bool VERIFY_SSL;
            };

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

#endif // STATUS_CONSTANTS
