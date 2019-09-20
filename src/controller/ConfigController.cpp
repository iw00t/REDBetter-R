#include "ConfigController.h"

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

        void ConfigController::loadConfig() {
            if (this->model.configFileExists()) {
                if (!this->model.configHasCorrectKeys()) {
                    this->view.displayConfigFieldMissing();
                    this->model.generateConfigFile();
                } else {
                    this->model.loadConfig();
                }
            } else {
                this->view.displayConfigMissing();
                this->model.generateConfigFile();
            }
        }

        std::map<std::string, std::string> ConfigController::getConfig() {
            return this->model.getConfigMap();
        }
    }
}
