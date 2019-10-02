#ifndef CONFIG_MODEL
#define CONFIG_MODEL

#include <string>
#include <map>

#include "../../opt/json.hpp"

namespace REDBetterR {
    namespace Config {
        const std::string FILE_PATH = "../config.json";

        class ConfigModel {
        public:
            ConfigModel() {}
            ~ConfigModel() {}
            bool configFileExists(const std::string & filePath = FILE_PATH);
            void generateConfigFile(const std::string & filePath = FILE_PATH);
            bool configHasCorrectKeys(const std::string & filePath = FILE_PATH);
            void loadConfig(const std::string & filePath = FILE_PATH);
            std::map<std::string, std::string> getConfigMap();

        private:
            std::map<std::string, std::string> configMap;
            bool jsonKeyExists(const nlohmann::json & j, const std::string & key);
        };
    }
}

#endif //CONFIG_MODEL
