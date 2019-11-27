#include "ConfigView.h"
#include <iostream>
#include <sstream>
#include <iterator>

namespace REDBetterR {
    namespace Config {
        void ConfigView::displayConfigMissing() const {
            std::cout << "The config.json file is missing. Generating a new one..." << std::endl;
        }

        void ConfigView::displayConfigFieldMissing() const {
            std::cout << "Some field(s) are missing in the config file. Generating a new one..." << std::endl;
        }

        void ConfigView::displayEmptyFields(const std::vector<std::string> & emptyFields) const {
            std::cout << "The following field(s) in the config file are empty, please ensure that they have a value:" << std::endl;
            std::string emptyFieldsString;
            for (const auto & field: emptyFields) {
                emptyFieldsString += field + ", ";
            }
            std::cout << emptyFieldsString.substr(0, emptyFieldsString.size() - 2) << std::endl;
        }
    }
}
