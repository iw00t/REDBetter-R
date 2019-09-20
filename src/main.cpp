#include "model/ConfigModel.h"
#include "view/ConfigView.h"
#include "controller/ConfigController.h"

int main() {
    REDBetterR::Config::ConfigModel configModel;
    REDBetterR::Config::ConfigView configView;

    REDBetterR::Config::ConfigController configController(configModel, configView);

    configController.loadConfig();
}
