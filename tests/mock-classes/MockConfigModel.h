#ifndef MOCK_CONFIG_MODEL
#define MOCK_CONFIG_MODEL

#include "gmock/gmock.h"

#include "../../src/model/ConfigModelInterface.h"


class MockConfigModel : public REDBetterR::Config::ConfigModelInterface {
public:
    MOCK_CONST_METHOD1(configFileExists, bool(const std::string &));
    MOCK_CONST_METHOD1(generateConfigFile, void(const std::string &));
    MOCK_CONST_METHOD1(configHasCorrectKeys, bool(const std::string &));
    MOCK_CONST_METHOD1(emptyConfigFields, std::vector<std::string>(const std::string &));
    MOCK_METHOD1(loadConfig, void(const std::string &));
    MOCK_CONST_METHOD0(getConfigMap, std::map<std::string, std::string>());
};

#endif //MOCK_CONFIG_MODEL
