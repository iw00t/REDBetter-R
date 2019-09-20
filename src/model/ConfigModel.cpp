#include "ConfigModel.h"
#include <fstream>
#include <iomanip>
#include <vector>

namespace REDBetterR {
    namespace Config {
        bool ConfigModel::configFileExists(const std::string & filePath) {
            std::ifstream configFile(filePath);
            return !configFile.fail();
        }

        void ConfigModel::generateConfigFile(const std::string & filePath) {
            std::ofstream configFile(filePath);
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

        bool ConfigModel::configHasCorrectKeys(const std::string & filePath) {
            std::ifstream configFile(filePath);
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

        bool ConfigModel::jsonKeyExists(const nlohmann::json & j, const std::string & key) {
            return j.find(key) != j.end();
        }
    }
}
