#ifndef CONFIG_MODEL
#define CONFIG_MODEL

#include "../constants/ConfigConstants.cpp"

#include "../../opt/json.hpp"

#include <vector>
#include <string>
#include <map>

namespace REDBetterR {
    namespace Config {
        class ConfigModel {
        public:
            ConfigModel() {}
            ~ConfigModel() {}
            bool configFileExists(const std::string & filePath = Constants::FILE_PATH);
            void generateConfigFile(const std::string & filePath = Constants::FILE_PATH);
            bool configHasCorrectKeys(const std::string & filePath = Constants::FILE_PATH);
            std::vector<std::string> emptyConfigFields(const std::string & filePath = Constants::FILE_PATH);
            void loadConfig(const std::string & filePath = Constants::FILE_PATH);
            std::map<std::string, std::string> getConfigMap();

        private:
            std::map<std::string, std::string> configMap;
            bool jsonKeyExists(const nlohmann::json & j, const std::string & key);
        };
    }
}

#endif //CONFIG_MODEL
