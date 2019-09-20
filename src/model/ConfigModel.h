#ifndef CONFIG_MODEL
#define CONFIG_MODEL

#include "../../includes/json.hpp"
#include <string>

namespace REDBetterR {
    namespace Config {
        const std::string FILE_PATH = "config.json";

        class ConfigModel {
        public:
            ConfigModel() {}
            ~ConfigModel() {}
            bool configFileExists(const std::string & filePath = FILE_PATH);
            void generateConfigFile(const std::string & filePath = FILE_PATH);
            bool configHasCorrectKeys(const std::string & filePath = FILE_PATH);

        private:
            std::string username;
            std::string password;
            std::string sessionCookie;
            std::string authkey;
            std::string passkey;
            std::string userId;
            std::string tracker;
            std::string lastRequest;
            std::string rateLimit;
            bool jsonKeyExists(const nlohmann::json & j, const std::string & key);
        };
    }
}

#endif //CONFIG_MODEL
