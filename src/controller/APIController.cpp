#include "APIController.h"

namespace REDBetterR {
    namespace API {
        APIController::APIController(APIModel & model, APIView & view) : BaseController(model, view) {}

        void APIController::login() {
            bool loginSuccessful = false;
            if (this->getModel()->sessionCookieSet()) {
                this->getView()->displayLoginWithCookie();
                loginSuccessful = this->getModel()->loginCookie();
            } else {
                this->getView()->displayLoginWithUsernamePassword();
                loginSuccessful = this->getModel()->loginUsernamePassword();
            }

            if (this->getModel()->loginCookie()) {
                this->getView()->displayLoginSuccessful();
            } else {
                this->getView()->displayLoginFailed();
            }
        }

        APIModel* APIController::getModel(){
            return dynamic_cast<APIModel*>(BaseController::getModel());
        }

        APIView* APIController::getView(){
            return dynamic_cast<APIView*>(BaseController::getView());
        }
    }
}
