#include "model/ConfigModel.h"
#include "view/ConfigView.h"
#include "controller/ConfigController.h"

int main() {
    ConfigModel configModel;
    ConfigView configView;

    ConfigController configController(configModel, configView);

    configController.loadConfig();
}