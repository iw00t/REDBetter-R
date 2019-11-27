#ifndef CONFIG_VIEW_INTERFACE
#define CONFIG_VIEW_INTERFACE

#include "BaseViewInterface.h"

#include <string>
#include <vector>

namespace REDBetterR {
    namespace Config {
        class ConfigViewInterface : public BaseViewInterface {
        public:
            ~ConfigViewInterface() override = default;
            virtual void displayConfigMissing() const = 0;
            virtual void displayConfigFieldMissing() const = 0;
            virtual void displayEmptyFields(const std::vector<std::string> & emptyFields) const = 0;
        };
    }
}

#endif // CONFIG_VIEW_INTERFACE