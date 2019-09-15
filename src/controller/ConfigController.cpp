#include "ConfigController.h"
#include <iostream>

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
    if (this->model.configFileExists() == 0) {
        if (!this->model.configHasCorrectKeys()) {
            this->view.displayConfigFieldMissing();
            this->model.generateConfigFile();
        }
    } else {
        this->view.displayConfigMissing();
        this->model.generateConfigFile();
    }
}
