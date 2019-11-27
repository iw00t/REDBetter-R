#include "APIView.h"

#include "../constants/APIConstants.cpp"

#include <iostream>
#include <iomanip>

namespace REDBetterR {
    namespace API {
        void APIView::displayLoginWithCookie() const {
            this->displayLoginBanner();
            std::cout << "Attempting login with session cookie..." << std::endl;
        }

        void APIView::displayLoginWithUsernamePassword() const {
            this->displayLoginBanner();
            std::cout << "Attempting login with username and password..." << std::endl;
        }

        void APIView::displayLoginSuccessful() const {
            std::cout << "Login successful..." << std::endl;
        }

        void APIView::displayLoginFailed() const {
            std::cout << "Login failed. Please review your config file..." << std::endl;
        }

        void APIView::displayUserInfo(const nlohmann::json & userInfo) const {
            this->displaySpacer();
            std::cout << "User Information" << std::endl;
            this->displaySpacer();
            std::cout << std::left
                << std::setw(Constants::OUTPUT_SPACING)
                << "Username"
                << Constants::OUTPUT_SPACER
                << userInfo[Constants::USERNAME_FIELD].get<std::string>()
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::OUTPUT_SPACING)
                << "Class"
                << Constants::OUTPUT_SPACER
                << userInfo[Constants::USER_STATS_FIELD][Constants::CLASS_FIELD].get<std::string>()
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::OUTPUT_SPACING)
                << "Uploaded"
                << Constants::OUTPUT_SPACER
                << this->bytesToGigabytes(userInfo[Constants::USER_STATS_FIELD][Constants::UPLOADED_FIELD].get<double>())
                << " GB"
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::OUTPUT_SPACING)
                << "Downloaded"
                << Constants::OUTPUT_SPACER
                << this->bytesToGigabytes(userInfo[Constants::USER_STATS_FIELD][Constants::DOWNLOADED_FIELD].get<double>())
                << " GB"
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::OUTPUT_SPACING)
                << "Ratio"
                << Constants::OUTPUT_SPACER
                << userInfo[Constants::USER_STATS_FIELD][Constants::RATIO_FIELD].get<float>()
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::OUTPUT_SPACING)
                << "Required Ratio"
                << Constants::OUTPUT_SPACER
                << userInfo[Constants::USER_STATS_FIELD][Constants::REQUIRED_RATIO_FIELD].get<float>()
                << std::endl;
            this->displaySpacer();
        }

        void APIView::displayLoginBanner() const {
            this->displaySpacer();
            std::cout << "Login" << std::endl;
            this->displaySpacer();
        }

        std::string APIView::bytesToGigabytes(const double & bytes) const {
            return std::to_string(bytes/1073741824);
        }
    }
}
