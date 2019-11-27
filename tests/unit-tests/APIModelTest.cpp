#include "TestCase.h"
#include "../../src/model/APIModel.h"

#include <fstream>

class APIModelTest : public TestCase {
public:
    APIModelTest() : TestCase() {}
    REDBetterR::API::APIModel apiModel;

    std::map<std::string, std::string> loadConfig(const std::string & filePath) {
        std::ifstream configFile(filePath);
        nlohmann::json configJson;
        configFile >> configJson;
        std::map<std::string, std::string> configMap = configJson;
        return configMap;
    }
};

TEST_F(APIModelTest, sessionCookieSet_returnsTrueWhenSessionCookieFieldPopulated) {
    ASSERT_TRUE(apiModel.sessionCookieSet(this->loadConfig("../tests/mock-data/config-files/all-keys.json")));
}

TEST_F(APIModelTest, sessionCookieSet_returnsFalseWhenSessionCookieFieldEmpty) {
    ASSERT_FALSE(apiModel.sessionCookieSet(this->loadConfig("../tests/mock-data/config-files/not-set-session-cookie.json")));
}
