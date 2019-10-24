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
            if (this->model.sessionCookieSet()) {
                this->view.displayLoginWithCookie();
                this->model.loginCookie();
            } else {
                this->view.displayLoginWithUsernamePassword();
                if (this->model.loginUsernamePassword()) {
                    this->view.displayLoginSuccessful();
                } else {
                    this->view.displayLoginFailed();
                }
            }
        }
    }
}
