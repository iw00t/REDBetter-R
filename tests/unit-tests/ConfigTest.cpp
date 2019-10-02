#include "TestCase.h"
#include "../../src/model/ConfigModel.h"

class ConfigTest : public TestCase {
public:
    ConfigTest() : TestCase() {}
    REDBetterR::Config::ConfigModel configModel;
};

TEST_F(ConfigTest, CheckConfigExistsWithExistingFile) {
    ASSERT_EQ(configModel.configFileExists("../tests/mock-data/all-keys.json"), true);
}

TEST_F(ConfigTest, CheckConfigExistsWithNonExistantFile) {
    ASSERT_EQ(configModel.configFileExists("../tests/mock-data/not-a-file.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysDoesNotFlagWhenAllKeysPresent) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/all-keys.json"), true);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingUsernameField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-username.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingPasswordField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-password.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingSessionCookieField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-session-cookie.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingDataDirField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-data-dir.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingOutputDirField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-output-dir.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingTorrentDirField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-torrent-dir.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingFormatsField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-formats.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingMediaField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-media.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissing24bitBehaviourField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-24bit-behaviour.json"), false);
}

TEST_F(ConfigTest, CheckConfigKeysFlagsMissingPieceLengthField) {
    ASSERT_EQ(configModel.configHasCorrectKeys("../tests/mock-data/missing-piece-length.json"), false);
}

TEST_F(ConfigTest, CheckMapCreatedFromConfigFile) {
    configModel.loadConfig("../tests/mock-data/all-keys.json");
    ASSERT_EQ(configModel.getConfigMap().size(), 10);
}
