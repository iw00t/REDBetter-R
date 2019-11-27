#ifndef CONFIG_CONTROLLER_INTERFACE
#define CONFIG_CONTROLLER_INTERFACE

#include "BaseControllerInterface.h"
#include "../model/ConfigModel.h"
#include "../view/ConfigView.h"

#include <map>

namespace REDBetterR {
    namespace Config {
        class ConfigControllerInterface : public BaseControllerInterface {
        public:
            ~ConfigControllerInterface() override = default;
            virtual bool loadConfig(const std::string &) const = 0;
            virtual std::map<std::string, std::string> getConfig() const = 0;
        };
    }
}

#endif //CONFIG_CONTROLLER_INTERFACE
