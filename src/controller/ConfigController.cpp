#include "ConfigController.h"


namespace REDBetterR {
    namespace Config {
        ConfigController::ConfigController(ConfigModelInterface & model, ConfigViewInterface & view) : BaseController(model, view) {}

        bool ConfigController::loadConfig(const std::string & filePath) const {
            if (this->getModel()->configFileExists(filePath)) {
                if (!this->getModel()->configHasCorrectKeys(filePath)) {
                    this->getView()->displayConfigFieldMissing();
                    this->getModel()->generateConfigFile(filePath);
                } else if (this->getModel()->emptyConfigFields(filePath).size() != 0) {
                    this->getView()->displayEmptyFields(this->getModel()->emptyConfigFields(filePath));
                } else {
                    this->getModel()->loadConfig(filePath);
                    return true;
                }
            } else {
                this->getView()->displayConfigMissing();
                this->getModel()->generateConfigFile(filePath);
            }
            return false;
        }

        std::map<std::string, std::string> ConfigController::getConfig() const {
            return this->getModel()->getConfigMap();
        }

        ConfigModelInterface* ConfigController::getModel() const {
            return dynamic_cast<ConfigModelInterface*>(BaseController::getModel());
        }

        ConfigViewInterface* ConfigController::getView() const {
            return dynamic_cast<ConfigViewInterface*>(BaseController::getView());
        }
    }
}
