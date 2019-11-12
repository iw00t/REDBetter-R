#ifndef CONFIG_VIEW
#define CONFIG_VIEW

#include "BaseView.h"

#include <string>
#include <vector>

namespace REDBetterR {
    namespace Config {
        class ConfigView : public BaseView {
        public:
            void displayConfigMissing();
            void displayConfigFieldMissing();
            void displayEmptyFields(const std::vector<std::string> & emptyFields);
        };
    }
}

#endif // CONFIG_VIEW