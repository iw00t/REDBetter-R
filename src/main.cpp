#include "controller/ConfigController.h"
#include "controller/APIController.h"
#include "controller/StatusController.h"

#include "common/constants/APIConstants.h"
#include "common/constants/ConfigConstants.h"
#include "common/constants/StatusConstants.h"

#include "common/factory/ControllerFactory.h"


int main() {
    auto statusController = std::dynamic_pointer_cast<REDBetterR::Status::StatusController>(REDBetterR::Factory::ControllerFactory::create(REDBetterR::Status::Constants::NAME));
    statusController->status();

    auto configController = std::dynamic_pointer_cast<REDBetterR::Config::ConfigController>(REDBetterR::Factory::ControllerFactory::create(REDBetterR::Config::Constants::NAME));

    if (configController->loadConfig(REDBetterR::Config::Constants::File::FILE_PATH)) {
        std::map<std::string, std::string> config = configController->getConfig();

        auto apiController = std::dynamic_pointer_cast<REDBetterR::API::APIController>(REDBetterR::Factory::ControllerFactory::create(REDBetterR::API::Constants::NAME));
        apiController->login(config);
    }
}
