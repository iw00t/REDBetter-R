#include "../headers/APIView.h"

#include <iostream>

void APIView::displayConfigMissing() {
    std::cout << "The config.json file is missing. Generating a new one..." << std::endl;
}