#include "APIController.h"

namespace REDBetterR {
    namespace API {
        APIController::APIController(APIModel model, APIView view) {
            this->setModel(model);
            this->setView(view);
        }

        void APIController::setModel(APIModel model) {
            this->model = model;
        }

        void APIController::setView(APIView view) {
            this->view = view;
        }

        void APIController::login() {
            bool loginSuccessful = false;
            if (this->model.sessionCookieSet()) {
                this->view.displayLoginWithCookie();
                loginSuccessful = this->model.loginCookie();
            } else {
                this->view.displayLoginWithUsernamePassword();
                loginSuccessful = this->model.loginUsernamePassword();
            }

            if (this->model.loginCookie()) {
                this->view.displayLoginSuccessful();
            } else {
                this->view.displayLoginFailed();
            }
        }
    }
}
