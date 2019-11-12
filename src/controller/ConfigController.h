#ifndef CONFIG_CONTROLLER
#define CONFIG_CONTROLLER

#include "BaseController.h"
#include "../model/ConfigModel.h"
#include "../view/ConfigView.h"

#include <map>

namespace REDBetterR {
    namespace Config {
        class ConfigController : public BaseController {
        public:
            ConfigController(ConfigModel & model, ConfigView & view);
            void setModel(ConfigModel model);
            void setView(ConfigView view);
            bool loadConfig();
            std::map<std::string, std::string> getConfig();

        private:
            ConfigModel* getModel();
            ConfigView* getView();
        };
    }
}

#endif //CONFIG_CONTROLLER
