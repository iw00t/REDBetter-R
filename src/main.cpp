#include "model/ConfigModel.h"
#include "view/ConfigView.h"
#include "controller/ConfigController.h"
#include "model/APIModel.h"
#include "view/APIView.h"
#include "controller/APIController.h"

int main() {
    REDBetterR::Config::ConfigModel configModel;
    REDBetterR::Config::ConfigView configView;
    REDBetterR::Config::ConfigController configController(configModel, configView);

    configController.loadConfig();
    std::map<std::string, std::string> config = configController.getConfig();

    REDBetterR::API::APIModel apiModel(config);
    REDBetterR::API::APIView apiView;
    REDBetterR::API::APIController apiController(apiModel, apiView);

    apiController.login();
}
