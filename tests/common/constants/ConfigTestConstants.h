#ifndef CONFIG_TEST_CONSTANTS
#define CONFIG_TEST_CONSTANTS

#include <string>
#include <vector>


namespace REDBetterR {
    namespace ConfigTest {
        namespace Constants {
            const std::string NAME = "config";

            class File {
            public:
                static const std::string FILE_PATH;
            };

            class JSON {
            public:
                static const std::vector<std::string> JSON_FIELDS;
                static const std::vector<std::string> REQUIRED_JSON_FIELDS;
            };
        }
    }
}

#endif // CONFIG_TEST_CONSTANTS
