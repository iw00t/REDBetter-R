#include "StatusView.h"

#include "../constants/StatusConstants.h"

#include <iostream>
#include <iomanip>


namespace REDBetterR {
    namespace Status {
        void StatusView::displayStatus(const nlohmann::json & status) const {
            this->displayStatusBanner();
            for (const auto & service : Constants::JSON::SERVICES) {
                std::cout << std::left
                          << std::setw(Constants::Output::SPACING)
                          << service.first
                          << " : ";
                this->displayServiceStatus(*status.find(service.second));
            }
        }

        void StatusView::displayServiceStatus(const nlohmann::json & status) const {
            std::string online = status.find(Constants::JSON::STATUS)->get<std::string>();
            if (online == Constants::Online::OFFLINE_STATUS_VALUE) {
                online = Constants::Online::OFFLINE_STATUS_DISPLAY;
            } else if (online == Constants::Online::ONLINE_STATUS_VALUE) {
                online = Constants::Online::ONLINE_STATUS_DISPLAY;
            } else if (online == Constants::Online::UNSTABLE_STATUS_VALUE) {
                online = Constants::Online::UNSTABLE_STATUS_DISPLAY;
            } else {
                online = Constants::Online::UNKNOWN_STATUS_DISPLAY;
            }
            std::string latency = status.find(Constants::JSON::LATENCY)->get<std::string>();
            std::cout << "Online?: "
                      << online 
                      << ", Latency: " 
                      << latency
                      << std::endl;
        }

        void StatusView::displayStatusBanner() const {
            this->displaySpacer();
            std::cout << "Redacted Status" << std::endl;
            this->displaySpacer();
        }
    }
}
