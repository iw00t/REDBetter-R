#include "ConfigView.h"
#include <iostream>

void ConfigView::displayConfigMissing() {
    std::cout << "The config.json file is missing. Generating a new one..." << std::endl;
}

void ConfigView::displayConfigFieldMissing() {
    std::cout << "Some field(s) is missing in the config file. Generating a new one..." << std::endl;
}
