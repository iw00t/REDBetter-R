#include "model/ConfigModel.h"
#include "view/ConfigView.h"
#include "controller/ConfigController.h"
#include "model/APIModel.h"
#include "view/APIView.h"
#include "controller/APIController.h"
#include "constants/ConfigConstants.cpp"


int main() {
    REDBetterR::Config::ConfigModel configModel;
    REDBetterR::Config::ConfigView configView;
    REDBetterR::Config::ConfigController configController(configModel, configView);

    if (configController.loadConfig(REDBetterR::Config::Constants::FILE_PATH)) {
        std::map<std::string, std::string> config = configController.getConfig();

        REDBetterR::API::APIModel apiModel;
        REDBetterR::API::APIView apiView;
        REDBetterR::API::APIController apiController(apiModel, apiView);

        apiController.login(config);
    }
}
