#ifndef CONFIG_VIEW
#define CONFIG_VIEW

#include <string>
#include <vector>

namespace REDBetterR {
    namespace Config {
        class ConfigView {
        public:
            ConfigView() {}
            ~ConfigView() {}
            void displayConfigMissing();
            void displayConfigFieldMissing();
            void displayEmptyFields(const std::vector<std::string> & emptyFields);
        };
    }
}

#endif // CONFIG_VIEW