#include "APIView.h"

#include <iostream>

void APIView::displayConfigMissing() {
    std::cout << "The config.json file is missing. Generating a new one..." << std::endl;
}

void APIView::displayConfigFieldMissing() {
    std::cout << "Some field(s) is missing in the config file. Generating a new one..." << std::endl;
}
