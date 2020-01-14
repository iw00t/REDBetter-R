#include "ConfigController.h"


namespace REDBetterR {
    namespace Config {
        ConfigController::ConfigController(std::shared_ptr<ConfigModelInterface> & model, std::shared_ptr<ConfigViewInterface> & view) : BaseController(model, view) {}

        bool ConfigController::loadConfig(const std::string & filePath) {
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

        std::map<std::string, std::string> ConfigController::getConfig() {
            return this->getModel()->getConfigMap();
        }

        std::shared_ptr<ConfigModelInterface> ConfigController::getModel() {
            return std::dynamic_pointer_cast<ConfigModelInterface>(BaseController::getModel());
        }

        std::shared_ptr<ConfigViewInterface> ConfigController::getView() {
            return std::dynamic_pointer_cast<ConfigViewInterface>(BaseController::getView());
        }
    }
}
