#include "APIController.h"

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
