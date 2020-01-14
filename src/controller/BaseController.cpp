#include "BaseController.h"


namespace REDBetterR {
    BaseController::BaseController(std::shared_ptr<BaseModelInterface> model, std::shared_ptr<BaseViewInterface> view) {
        this->setModel(model);
        this->setView(view);
    }

    void BaseController::setModel(std::shared_ptr<BaseModelInterface> model) {
        this->model = model;
    }

    void BaseController::setView(std::shared_ptr<BaseViewInterface> view) {
        this->view = view;
    }

    std::shared_ptr<BaseModelInterface> BaseController::getModel() const {
        return this->model;
    }

    std::shared_ptr<BaseViewInterface> BaseController::getView() const {
        return this->view;
    }
}
