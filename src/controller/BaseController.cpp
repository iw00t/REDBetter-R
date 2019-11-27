#include "BaseController.h"


namespace REDBetterR {
    BaseController::BaseController(BaseModelInterface & model, BaseViewInterface & view) {
        this->model = &model;
        this->view = &view;
    }

    void BaseController::setModel(BaseModelInterface & model) {
        this->model = &model;
    }

    void BaseController::setView(BaseViewInterface & view) {
        this->view = &view;
    }

    BaseModelInterface* BaseController::getModel() const {
        return dynamic_cast<BaseModelInterface*>(this->model);
    }

    BaseViewInterface* BaseController::getView() const {
        return dynamic_cast<BaseViewInterface*>(this->view);
    }
}
