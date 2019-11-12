#ifndef API_CONTROLLER
#define API_CONTROLLER

#include "BaseController.h"
#include "../model/APIModel.h"
#include "../view/APIView.h"

namespace REDBetterR {
    namespace API {
        class APIController : public BaseController {
        public:
            APIController(APIModel & model, APIView & view);
            void setModel(APIModel model);
            void setView(APIView view);
            void login();

        private:
            APIModel* getModel();
            APIView* getView();
        };
    }
}

#endif //API_CONTROLLER
