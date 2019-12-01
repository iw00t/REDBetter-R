#include "StatusController.h"

namespace REDBetterR {
    namespace Status {
        StatusController::StatusController(StatusModelInterface & model, StatusViewInterface & view) : BaseController(model, view) {}

        void StatusController::status() {
            this->getView()->displayStatus(this->getModel()->getStatus());
        }

        StatusModelInterface* StatusController::getModel(){
            return dynamic_cast<StatusModelInterface*>(BaseController::getModel());
        }

        StatusViewInterface* StatusController::getView(){
            return dynamic_cast<StatusViewInterface*>(BaseController::getView());
        }
    }
}
