#ifndef CONFIG_CONTROLLER
#define CONFIG_CONTROLLER

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
            void loadConfig();

        private:
            ConfigModel model;
            ConfigView view;
        };
    }
}

#endif //CONFIG_CONTROLLER
