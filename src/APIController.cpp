#include "../headers/APIController.h"
#include <iostream>

APIController::APIController(APIModel model, APIView view) {
    this->setModel(model);
    this->setView(view);
}

void APIController::setModel(APIModel model) {
    this->model = model;
}

void APIController::setView(APIView view) {
    this->view = view;
}

void APIController::loadConfig() {
    if (this->model.checkConfigExists() == 0) {
        
    } else {
        this->view.displayConfigMissing();
        this->model.generateConfigFile();
    }
}
