#include "APIView.h"

#include "../common/constants/APIConstants.h"

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
                << std::setw(Constants::Output::SPACING)
                << "Username"
                << Constants::Output::SPACER
                << userInfo[Constants::Field::USERNAME].get<std::string>()
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::Output::SPACING)
                << "Class"
                << Constants::Output::SPACER
                << userInfo[Constants::Field::USER_STATS][Constants::Field::CLASS].get<std::string>()
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::Output::SPACING)
                << "Uploaded"
                << Constants::Output::SPACER
                << this->bytesToGigabytes(userInfo[Constants::Field::USER_STATS][Constants::Field::UPLOADED].get<double>())
                << " GB"
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::Output::SPACING)
                << "Downloaded"
                << Constants::Output::SPACER
                << this->bytesToGigabytes(userInfo[Constants::Field::USER_STATS][Constants::Field::DOWNLOADED].get<double>())
                << " GB"
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::Output::SPACING)
                << "Ratio"
                << Constants::Output::SPACER
                << userInfo[Constants::Field::USER_STATS][Constants::Field::RATIO].get<float>()
                << std::endl;
            std::cout << std::left
                << std::setw(Constants::Output::SPACING)
                << "Required Ratio"
                << Constants::Output::SPACER
                << userInfo[Constants::Field::USER_STATS][Constants::Field::REQUIRED_RATIO].get<float>()
                << std::endl;
            this->displaySpacer();
        }

        void APIView::displayObtainingSnatchedTorrents() const {
            std::cout << "Obtaining snatched torrents..." << std::endl;
        }

        void APIView::displayObtainingTranscodeCandidates(int current, int total) const {
            std::cout << "Obtaining transcode candidates (" << current << " / " << total <<  ")..." << std::endl;
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
