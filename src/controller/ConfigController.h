#ifndef CONFIG_CONTROLLER
#define CONFIG_CONTROLLER

#include "ConfigControllerInterface.h"
#include "BaseController.h"
#include "../model/ConfigModel.h"
#include "../model/ConfigModelInterface.h"
#include "../view/ConfigView.h"
#include "../view/ConfigViewInterface.h"

#include <map>


namespace REDBetterR {
    namespace Config {
        class ConfigController : public BaseController, public ConfigControllerInterface {
        public:
            ConfigController() = default;
            explicit ConfigController(ConfigModelInterface & model, ConfigViewInterface & view);
            bool loadConfig(const std::string & filePath) const;
            std::map<std::string, std::string> getConfig() const;

        private:
            ConfigModelInterface* getModel() const;
            ConfigViewInterface* getView() const;
        };
    }
}

#endif //CONFIG_CONTROLLER
