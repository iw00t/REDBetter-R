#include "APIController.h"

namespace REDBetterR {
    namespace API {
        APIController::APIController(APIModelInterface & model, APIViewInterface & view) : BaseController(model, view) {}

        void APIController::login(const std::map<std::string, std::string> & config) {
            bool loginSuccessful = false;
            if (this->getModel()->sessionCookieSet(config)) {
                this->getView()->displayLoginWithCookie();
                loginSuccessful = this->getModel()->loginCookie(config);
            } else {
                this->getView()->displayLoginWithUsernamePassword();
                loginSuccessful = this->getModel()->loginUsernamePassword(config);
            }

            if (loginSuccessful) {
                this->getView()->displayLoginSuccessful();
            } else {
                this->getView()->displayLoginFailed();
            }
        }

        APIModelInterface* APIController::getModel(){
            return dynamic_cast<APIModelInterface*>(BaseController::getModel());
        }

        APIViewInterface* APIController::getView(){
            return dynamic_cast<APIViewInterface*>(BaseController::getView());
        }
    }
}
