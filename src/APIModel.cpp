#include "../headers/APIModel.h"
#include "../lib/json.hpp"
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

bool APIModel::checkConfigExists() {
    std::ifstream configFile(this->FILE_PATH);
    return configFile.fail();
}

void APIModel::generateConfigFile() {
    std::ofstream configFile("config.json");
    json configTemplate = {
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
}
