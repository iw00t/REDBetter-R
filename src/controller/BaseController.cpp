#include "BaseController.h"
#include <iostream>

namespace REDBetterR {
    BaseController::BaseController(BaseModel & model, BaseView & view) {
        this->setModel(model);
        this->setView(view);
    }

    void BaseController::setModel(BaseModel & model) {
        this->model = &model;
    }

    void BaseController::setView(BaseView & view) {
        this->view = &view;
    }

    BaseModel* BaseController::getModel() {
        return dynamic_cast<BaseModel*>(this->model);
    }

    BaseView* BaseController::getView() {
        return dynamic_cast<BaseView*>(this->view);
    }
}
