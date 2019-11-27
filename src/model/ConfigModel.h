#ifndef CONFIG_MODEL
#define CONFIG_MODEL

#include "BaseModel.h"
#include "ConfigModelInterface.h"

#include "../../opt/json.hpp"

#include <vector>
#include <string>
#include <map>

namespace REDBetterR {
    namespace Config {
        class ConfigModel : public BaseModel, public ConfigModelInterface {
        public:
            bool configFileExists(const std::string & filePath) const;
            void generateConfigFile(const std::string & filePath) const;
            bool configHasCorrectKeys(const std::string & filePath) const;
            std::vector<std::string> emptyConfigFields(const std::string & filePath) const;
            void loadConfig(const std::string & filePath);
            std::map<std::string, std::string> getConfigMap() const;

        private:
            std::map<std::string, std::string> configMap;
            bool jsonKeyExists(const nlohmann::json & j, const std::string & key) const;
        };
    }
}

#endif //CONFIG_MODEL
