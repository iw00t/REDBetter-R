#ifndef API_CONTROLLER
#define API_CONTROLLER

#include "BaseController.h"
#include "../model/APIModel.h"
#include "../model/APIModelInterface.h"
#include "../view/APIView.h"
#include "../view/APIViewInterface.h"

namespace REDBetterR {
    namespace API {
        class APIController : public BaseController {
        public:
            APIController(APIModelInterface & model, APIViewInterface & view);
            void login(const std::map<std::string, std::string> & config);

        private:
            APIModelInterface* getModel();
            APIViewInterface* getView();
        };
    }
}

#endif //API_CONTROLLER
