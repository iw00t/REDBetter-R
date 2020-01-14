#include "APIController.h"

namespace REDBetterR {
    namespace API {
        APIController::APIController(std::shared_ptr<APIModelInterface> & model, std::shared_ptr<APIViewInterface> & view) : BaseController(model, view) {}

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
                this->getView()->displayUserInfo(this->getModel()->getUserInfo());
            } else {
                this->getView()->displayLoginFailed();
            }
        }

        std::shared_ptr<APIModelInterface> APIController::getModel() {
            return std::dynamic_pointer_cast<APIModelInterface>(BaseController::getModel());
        }

        std::shared_ptr<APIViewInterface> APIController::getView() {
            return std::dynamic_pointer_cast<APIViewInterface>(BaseController::getView());
        }
    }
}
