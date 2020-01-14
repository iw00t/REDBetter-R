#ifndef CONFIG_VIEW
#define CONFIG_VIEW

#include "BaseView.h"
#include "ConfigViewInterface.h"

#include <string>
#include <vector>

namespace REDBetterR {
    namespace Config {
        class ConfigView : public BaseView, public ConfigViewInterface {
        public:
            void displayConfigMissing() const;
            void displayConfigFieldMissing() const;
            void displayEmptyFields(const std::vector<std::string> & emptyFields) const;
        };
    }
}

#endif // CONFIG_VIEW