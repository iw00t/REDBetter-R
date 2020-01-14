#ifndef STATUS_CONTROLLER
#define STATUS_CONTROLLER

#include "BaseController.h"
#include "StatusControllerInterface.h"
#include "../model/StatusModelInterface.h"
#include "../view/StatusViewInterface.h"

namespace REDBetterR {
    namespace Status {
        class StatusController : public BaseController, public StatusControllerInterface {
        public:
            StatusController(std::shared_ptr<StatusModelInterface> & model, std::shared_ptr<StatusViewInterface> & view);
            void status();

        private:
            std::shared_ptr<StatusModelInterface> getModel();
            std::shared_ptr<StatusViewInterface> getView();
        };
    }
}

#endif // STATUS_CONTROLLER
