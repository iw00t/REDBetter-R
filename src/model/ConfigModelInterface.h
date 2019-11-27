#ifndef CONFIG_MODEL_INTERFACE
#define CONFIG_MODEL_INTERFACE

#include "BaseModelInterface.h"
#include "../constants/ConfigConstants.cpp"

#include <string>
#include <map>


namespace REDBetterR {
    namespace Config {
        class ConfigModelInterface : public BaseModelInterface {
        public:
            ~ConfigModelInterface() override = default;
            virtual bool configFileExists(const std::string & filePath) const = 0;
            virtual void generateConfigFile(const std::string & filePath = Constants::FILE_PATH) const = 0;
            virtual bool configHasCorrectKeys(const std::string & filePath = Constants::FILE_PATH) const = 0;
            virtual std::vector<std::string> emptyConfigFields(const std::string & filePath = Constants::FILE_PATH) const = 0;
            virtual void loadConfig(const std::string & filePath = Constants::FILE_PATH) = 0;
            virtual std::map<std::string, std::string> getConfigMap() const = 0;
        };
    }
}

#endif //CONFIG_MODEL_INTERFACE
