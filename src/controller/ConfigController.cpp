#include "ConfigController.h"
#include <iostream>

namespace REDBetterR {
    namespace Config {
        ConfigController::ConfigController(ConfigModel model, ConfigView view) {
            this->setModel(model);
            this->setView(view);
        }

        void ConfigController::setModel(ConfigModel model) {
            this->model = model;
        }

        void ConfigController::setView(ConfigView view) {
            this->view = view;
        }

        bool ConfigController::loadConfig() {
            if (this->model.configFileExists()) {
                if (!this->model.configHasCorrectKeys()) {
                    this->view.displayConfigFieldMissing();
                    this->model.generateConfigFile();
                } else if (this->model.emptyConfigFields().size() != 0) {
                    this->view.displayEmptyFields(this->model.emptyConfigFields());
                }
                else {
                    this->model.loadConfig();
                    return true;
                }
            } else {
                this->view.displayConfigMissing();
                this->model.generateConfigFile();
            }
            return false;
        }

        std::map<std::string, std::string> ConfigController::getConfig() {
            return this->model.getConfigMap();
        }
    }
}
