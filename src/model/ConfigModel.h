#ifndef CONFIG_MODEL
#define CONFIG_MODEL

#include <vector>
#include <string>
#include <map>

#include "../../opt/json.hpp"

namespace REDBetterR {
    namespace Config {
        const std::string FILE_PATH = "../config.json";
        const std::vector<std::string> JSON_FIELDS = {
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
        const std::vector<std::string> REQUIRED_JSON_FIELDS = {
            "username",
            "password",
            "data_dir",
            "output_dir",
            "torrent_dir",
            "formats",
            "media",
            "24bit_behaviour",
            "piece_length"
        };

        class ConfigModel {
        public:
            ConfigModel() {}
            ~ConfigModel() {}
            bool configFileExists(const std::string & filePath = FILE_PATH);
            void generateConfigFile(const std::string & filePath = FILE_PATH);
            bool configHasCorrectKeys(const std::string & filePath = FILE_PATH);
            std::vector<std::string> emptyConfigFields(const std::string & filePath = FILE_PATH);
            void loadConfig(const std::string & filePath = FILE_PATH);
            std::map<std::string, std::string> getConfigMap();

        private:
            std::map<std::string, std::string> configMap;
            bool jsonKeyExists(const nlohmann::json & j, const std::string & key);
        };
    }
}

#endif //CONFIG_MODEL
