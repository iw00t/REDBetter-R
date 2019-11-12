#include "ConfigController.h"
#include <iostream>

namespace REDBetterR {
    namespace Config {
        ConfigController::ConfigController(ConfigModel & model, ConfigView & view) : BaseController(model, view) {}

        bool ConfigController::loadConfig() {
            if (this->getModel()->configFileExists()) {
                if (!this->getModel()->configHasCorrectKeys()) {
                    this->getView()->displayConfigFieldMissing();
                    this->getModel()->generateConfigFile();
                } else if (this->getModel()->emptyConfigFields().size() != 0) {
                    this->getView()->displayEmptyFields(this->getModel()->emptyConfigFields());
                }
                else {
                    this->getModel()->loadConfig();
                    return true;
                }
            } else {
                this->getView()->displayConfigMissing();
                this->getModel()->generateConfigFile();
            }
            return false;
        }

        std::map<std::string, std::string> ConfigController::getConfig() {
            return this->getModel()->getConfigMap();
        }

        ConfigModel* ConfigController::getModel(){
            return dynamic_cast<ConfigModel*>(BaseController::getModel());
        }

        ConfigView* ConfigController::getView(){
            return dynamic_cast<ConfigView*>(BaseController::getView());
        }
    }
}
