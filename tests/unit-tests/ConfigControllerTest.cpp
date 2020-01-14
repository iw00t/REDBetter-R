#include "TestCase.h"

#include "../mock-classes/MockConfigModel.h"
#include "../mock-classes/MockConfigView.h"
#include "../../src/controller/ConfigController.h"

using testing::Return;


class ConfigControllerTest : public TestCase {
public:
    ConfigControllerTest() : TestCase() {
        this->mockConfigModel = std::make_shared<MockConfigModel>();
        this->mockConfigView = std::make_shared<MockConfigView>();
        std::shared_ptr<REDBetterR::Config::ConfigModelInterface> configModel = this->mockConfigModel;
        std::shared_ptr<REDBetterR::Config::ConfigViewInterface> configView = this->mockConfigView;
        this->configController = std::make_shared<REDBetterR::Config::ConfigController>(configModel, configView);
    }

    std::shared_ptr<MockConfigModel> mockConfigModel;
    std::shared_ptr<MockConfigView> mockConfigView;
    std::shared_ptr<REDBetterR::Config::ConfigController> configController;

    const std::string MOCK_FILE_PATH = "mockPath";
    const std::vector<std::string> MOCK_EMPTY_FIELDS = {"mock", "empty", "fields"};
    const std::vector<std::string> MOCK_NO_EMPTY_FIELDS = {};
    const std::map<std::string, std::string> MOCK_MAP = std::map<std::string, std::string>();
};

TEST_F(ConfigControllerTest, getConfig_ReturnsStringMap) {
    EXPECT_CALL(*mockConfigModel, getConfigMap()).Times(1).WillOnce(Return(MOCK_MAP));

    EXPECT_EQ(MOCK_MAP, configController->getConfig());
}

TEST_F(ConfigControllerTest, loadConfig_ConfigDoesNotExist) {
    EXPECT_CALL(*mockConfigModel, configFileExists(MOCK_FILE_PATH)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mockConfigView, displayConfigMissing()).Times(1);
    EXPECT_CALL(*mockConfigModel, generateConfigFile(MOCK_FILE_PATH)).Times(1);

    ASSERT_FALSE(configController->loadConfig(MOCK_FILE_PATH));
}

TEST_F(ConfigControllerTest, loadConfig_ConfigHasIncorrectKeys) {
    EXPECT_CALL(*mockConfigModel, configFileExists(MOCK_FILE_PATH)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockConfigModel, configHasCorrectKeys(MOCK_FILE_PATH)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mockConfigView, displayConfigFieldMissing()).Times(1);
    EXPECT_CALL(*mockConfigModel, generateConfigFile(MOCK_FILE_PATH)).Times(1);

    ASSERT_FALSE(configController->loadConfig(MOCK_FILE_PATH));
}

TEST_F(ConfigControllerTest, loadConfig_ConfigHasEmptyFields) {
    EXPECT_CALL(*mockConfigModel, configFileExists(MOCK_FILE_PATH)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockConfigModel, configHasCorrectKeys(MOCK_FILE_PATH)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockConfigModel, emptyConfigFields(MOCK_FILE_PATH)).Times(2).WillRepeatedly(Return(MOCK_EMPTY_FIELDS));
    EXPECT_CALL(*mockConfigView, displayEmptyFields(MOCK_EMPTY_FIELDS)).Times(1);

    ASSERT_FALSE(configController->loadConfig(MOCK_FILE_PATH));
}

TEST_F(ConfigControllerTest, loadConfig_ConfigLoadsCorrectly) {
    EXPECT_CALL(*mockConfigModel, configFileExists(MOCK_FILE_PATH)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockConfigModel, configHasCorrectKeys(MOCK_FILE_PATH)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockConfigModel, emptyConfigFields(MOCK_FILE_PATH)).Times(1).WillRepeatedly(Return(MOCK_NO_EMPTY_FIELDS));
    EXPECT_CALL(*mockConfigModel, loadConfig(MOCK_FILE_PATH)).Times(1);

    ASSERT_TRUE(configController->loadConfig(MOCK_FILE_PATH));
}
