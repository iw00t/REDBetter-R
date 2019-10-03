#include "ConfigModel.h"

#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

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
            for (const auto & field: JSON_FIELDS) {
                if (!jsonKeyExists(configContents, field)) {
                    return false;
                }
            }
            configFile.close();
            return true;
        }

        std::vector<std::string> ConfigModel::emptyConfigFields(const std::string & filePath) {
            std::vector<std::string> emptyFields;
            std::ifstream configFile(filePath);
            nlohmann::json configFields;
            configFile >> configFields;
            for (auto & field: configFields.items()) {
                if (field.value() == "" && std::find(REQUIRED_JSON_FIELDS.begin(), REQUIRED_JSON_FIELDS.end(), field.value().dump()) != REQUIRED_JSON_FIELDS.end()) {
                    emptyFields.push_back(field.key());
                }
            }
            return emptyFields;
        }

        bool ConfigModel::jsonKeyExists(const nlohmann::json & j, const std::string & key) {
            return j.find(key) != j.end();
        }

        void ConfigModel::loadConfig(const std::string & filePath) {
            std::ifstream configFile(filePath);
            nlohmann::json configJson;
            configFile >> configJson;
            std::map<std::string, std::string> configMap = configJson;
            this->configMap = configMap;
        }

        std::map<std::string, std::string> ConfigModel::getConfigMap() {
            return this->configMap;
        }
    }
}
