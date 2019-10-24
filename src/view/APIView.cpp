#include "APIView.h"

#include <iostream>

namespace REDBetterR {
    namespace API {
        void APIView::displayLoginWithCookie() {
            std::cout << "Attempting login with session cookie..." << std::endl;
        }

        void APIView::displayLoginWithUsernamePassword() {
            std::cout << "Attempting login with username and password..." << std::endl;
        }

        void APIView::displayLoginSuccessful() {
            std::cout << "Login successful..." << std::endl;
        }

        void APIView::displayLoginFailed() {
            std::cout << "Login failed. Please review your config file..." << std::endl;
        }
    }
}
