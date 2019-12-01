#include "model/ConfigModel.h"
#include "view/ConfigView.h"
#include "controller/ConfigController.h"
#include "model/APIModel.h"
#include "view/APIView.h"
#include "controller/APIController.h"
#include "model/StatusModel.h"
#include "view/StatusView.h"
#include "controller/StatusController.h"
#include "constants/ConfigConstants.h"
#include "common/CprHelper.h"
#include "common/JsonHelper.h"
#include <iostream>

int main() {
    REDBetterR::Common::CprHelper cprHelper;
    REDBetterR::Common::JsonHelper jsonHelper;
    REDBetterR::Status::StatusModel statusModel(cprHelper, jsonHelper);
    REDBetterR::Status::StatusView statusView;
    REDBetterR::Status::StatusController statusController(statusModel, statusView);
    statusController.status();

    REDBetterR::Config::ConfigModel configModel;
    REDBetterR::Config::ConfigView configView;
    REDBetterR::Config::ConfigController configController(configModel, configView);

    if (configController.loadConfig(REDBetterR::Config::Constants::File::FILE_PATH)) {
        std::map<std::string, std::string> config = configController.getConfig();

        REDBetterR::Common::CprHelper cprHelper;
        REDBetterR::Common::JsonHelper jsonHelper;
        REDBetterR::API::APIModel apiModel(cprHelper, jsonHelper);
        REDBetterR::API::APIView apiView;
        REDBetterR::API::APIController apiController(apiModel, apiView);

        apiController.login(config);
    }
}
