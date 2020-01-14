#ifndef API_CONTROLLER
#define API_CONTROLLER

#include "BaseController.h"
#include "APIControllerInterface.h"
#include "../model/APIModelInterface.h"
#include "../view/APIViewInterface.h"

namespace REDBetterR {
    namespace API {
        class APIController : public BaseController, public APIControllerInterface {
        public:
            APIController(std::shared_ptr<APIModelInterface> & model, std::shared_ptr<APIViewInterface> & view);
            void login(const std::map<std::string, std::string> & config);

        private:
            std::shared_ptr<APIModelInterface> getModel();
            std::shared_ptr<APIViewInterface> getView();
        };
    }
}

#endif //API_CONTROLLER
