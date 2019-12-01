#ifndef STATUS_CONTROLLER
#define STATUS_CONTROLLER

#include "BaseController.h"
#include "../model/StatusModelInterface.h"
#include "../view/StatusViewInterface.h"

namespace REDBetterR {
    namespace Status {
        class StatusController : public BaseController {
        public:
            StatusController(StatusModelInterface & model, StatusViewInterface & view);
            void status();

        private:
            StatusModelInterface* getModel();
            StatusViewInterface* getView();
        };
    }
}

#endif // STATUS_CONTROLLER
