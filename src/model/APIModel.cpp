#include "APIModel.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

bool APIModel::checkConfigExists() {
    std::ifstream configFile(this->FILE_PATH);
    return configFile.fail();
}

void APIModel::generateConfigFile() {
    std::ofstream configFile(this->FILE_PATH);
    nlohmann::json configTemplate = {
        {"username", ""},
        {"password", ""},
        {"session_cookie", ""},
        {"data_dir", ""},
        {"output_dir", ""},
        {"torrent_dir", ""},
        {"formats", ""},
        {"media", ""},
        {"24bit_behaviour", ""},
        {"piece_length", ""}
    };
    configFile << std::setw(4) << configTemplate << std::endl;
    configFile.close();
}

bool APIModel::checkConfigFields() {
    std::ifstream configFile(this->FILE_PATH);
    nlohmann::json configContents;
    configFile >> configContents;
    std::vector<std::string> jsonFields = {
        "username",
        "password",
        "session_cookie",
        "data_dir",
        "output_dir",
        "torrent_dir",
        "formats",
        "media",
        "24bit_behaviour",
        "piece_length"
    };

    for (const auto & field: jsonFields) {
        if (!jsonKeyExists(configContents, field)) {
            return false;
        }
    }
    configFile.close();
    return true;
}

bool APIModel::jsonKeyExists(const nlohmann::json & j, const std::string & key) {
    return j.find(key) != j.end();
}
