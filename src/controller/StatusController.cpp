#include "StatusController.h"

namespace REDBetterR {
    namespace Status {
        StatusController::StatusController(std::shared_ptr<StatusModelInterface> & model, std::shared_ptr<StatusViewInterface> & view) : BaseController(model, view) {}

        void StatusController::status() {
            this->getView()->displayStatus(this->getModel()->getStatus());
        }

        std::shared_ptr<StatusModelInterface> StatusController::getModel() {
            return std::dynamic_pointer_cast<StatusModelInterface>(BaseController::getModel());
        }

        std::shared_ptr<StatusViewInterface> StatusController::getView() {
            return std::dynamic_pointer_cast<StatusViewInterface>(BaseController::getView());
        }
    }
}
