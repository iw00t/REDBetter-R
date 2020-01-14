#ifndef CONFIG_CONTROLLER
#define CONFIG_CONTROLLER

#include "BaseController.h"
#include "ConfigControllerInterface.h"
#include "../model/ConfigModelInterface.h"
#include "../view/ConfigViewInterface.h"

#include <map>


namespace REDBetterR {
    namespace Config {
        class ConfigController : public BaseController, public ConfigControllerInterface {
        public:
            ConfigController(std::shared_ptr<ConfigModelInterface> & model, std::shared_ptr<ConfigViewInterface> & view);
            bool loadConfig(const std::string & filePath);
            std::map<std::string, std::string> getConfig();

        private:
            std::shared_ptr<ConfigModelInterface> getModel();
            std::shared_ptr<ConfigViewInterface> getView();
        };
    }
}

#endif //CONFIG_CONTROLLER
