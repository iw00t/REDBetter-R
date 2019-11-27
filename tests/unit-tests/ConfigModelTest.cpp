#include "TestCase.h"
#include "../../src/model/ConfigModel.h"

class ConfigModelTest : public TestCase {
public:
    ConfigModelTest() : TestCase() {}
    REDBetterR::Config::ConfigModel configModel;
};

TEST_F(ConfigModelTest, CheckConfigExistsWithExistingFile) {
    ASSERT_TRUE(configModel.configFileExists("../tests/mock-data/config-files/all-keys.json"));
}

TEST_F(ConfigModelTest, CheckConfigExistsWithNonExistantFile) {
    ASSERT_FALSE(configModel.configFileExists("../tests/mock-data/config-files/not-a-file.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysDoesNotFlagWhenAllKeysPresent) {
    ASSERT_TRUE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/all-keys.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingUsernameField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-username.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingPasswordField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-password.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingSessionCookieField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-session-cookie.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingDataDirField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-data-dir.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingOutputDirField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-output-dir.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingTorrentDirField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-torrent-dir.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingFormatsField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-formats.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingMediaField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-media.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissing24bitBehaviourField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-24bit-behaviour.json"));
}

TEST_F(ConfigModelTest, CheckConfigKeysFlagsMissingPieceLengthField) {
    ASSERT_FALSE(configModel.configHasCorrectKeys("../tests/mock-data/config-files/missing-piece-length.json"));
}

TEST_F(ConfigModelTest, CheckMapCreatedFromConfigFile) {
    configModel.loadConfig("../tests/mock-data/config-files/all-keys.json");
    ASSERT_EQ(configModel.getConfigMap().size(), 10);
}
