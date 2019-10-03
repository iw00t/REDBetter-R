#ifndef CONFIG_CONTROLLER
#define CONFIG_CONTROLLER

#include <map>

#include "../model/ConfigModel.h"
#include "../view/ConfigView.h"

namespace REDBetterR {
    namespace Config {
        class ConfigController {
        public:
            ConfigController(ConfigModel model, ConfigView view);
            ~ConfigController() {}
            void setModel(ConfigModel model);
            void setView(ConfigView view);
            bool loadConfig();
            std::map<std::string, std::string> getConfig();

        private:
            ConfigModel model;
            ConfigView view;
        };
    }
}

#endif //CONFIG_CONTROLLER
