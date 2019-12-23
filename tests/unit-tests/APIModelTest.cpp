#include "TestCase.h"

#include "../../src/model/APIModel.h"
#include "../../src/common/constants/APIConstants.h"
#include "../mock-classes/MockCprHelper.h"
#include "../mock-classes/MockJsonHelper.h"

#include <fstream>

using testing::Return;


class APIModelTest : public TestCase {
public:
    APIModelTest() : TestCase() {
        this->apiModel = new REDBetterR::API::APIModel(this->mockCprHelper, this->mockJsonHelper);
        this->MOCK_VALID_CONFIG = this->loadConfig("../tests/mock-data/config-files/all-keys.json");
        this->MOCK_EMPTY_FIELDS_CONFIG = this->loadConfig("../tests/mock-data/config-files/empty-fields.json");
        this->MOCK_MISSING_SESSION_COOKIE_CONFIG = this->loadConfig("../tests/mock-data/config-files/missing-session-cookie.json");
    }

    MockCprHelper mockCprHelper;
    MockJsonHelper mockJsonHelper;
    REDBetterR::API::APIModel* apiModel;
    std::string MOCK_AUTHKEY = "mockAuthkey";
    std::string MOCK_PASSKEY = "mockPasskey";
    unsigned int MOCK_USER_ID = 2060;
    std::map<std::string, std::string> MOCK_VALID_CONFIG;
    std::map<std::string, std::string> MOCK_EMPTY_FIELDS_CONFIG;
    std::map<std::string, std::string> MOCK_MISSING_SESSION_COOKIE_CONFIG;
    std::map<std::string, std::string> MOCK_REQUEST_GET_PARAMETERS;
    cpr::Response MOCK_INDEX_RESPONSE_SUCCESS = cpr::Response({
        200,
        "{'status':'success','response':{'username':'iw00t','id':2060,'authkey':'mockAuthkey','passkey':'mockPasskey','notifications':{'messages':0,'notifications':72,'newAnnouncement':false,'newBlog':false,'newSubscriptions':false},'userstats':{'uploaded':732119527158,'downloaded':451355719295,'ratio':1.62,'requiredratio':0.6,'class':'Elite TM'}}}",
        cpr::Header(),
        cpr::Url("https://redacted.ch/ajax.php?action=index"),
        0.5,
        cpr::Cookies(),
        cpr::Error()
    });
    nlohmann::json MOCK_INDEX_RESPONSE_SUCCESS_JSON = {
        {"response", {
            {"authkey", MOCK_AUTHKEY},
            {"id", MOCK_USER_ID},
            {"notifications", {
                    {"messages", 0},
                    {"newAnnouncement", false},
                    {"newBlog", false},
                    {"newSubscriptions", false},
                    {"notifications", 72}
                }
            },
            {"passkey", MOCK_PASSKEY},
            {"username", "iw00t"},
            {"userstats", {
                    {"class", "Elite TM"},
                    {"downloaded", 451355719295},
                    {"ratio", 1.62},
                    {"requiredratio", 0.6},
                    {"uploaded", 732119559926}
                }
            }
        }},
        {"status", "success"}
    };
    nlohmann::json MOCK_EMPTY_JSON = {};
    std::map<std::string, std::string> MOCK_EMPTY_CONFIG = {};
    std::string EMPTY_STRING = "";
    unsigned int ZERO_UNSIGNED_INT = 0;

    std::map<std::string, std::string> loadConfig(const std::string & filePath) {
        std::ifstream configFile(filePath);
        nlohmann::json configJson;
        configFile >> configJson;
        std::map<std::string, std::string> configMap = configJson;
        return configMap;
    }
};

TEST_F(APIModelTest, sessionCookieSet_returnsTrueWhenSessionCookieFieldPopulated) {
    ASSERT_TRUE(apiModel->sessionCookieSet(this->MOCK_VALID_CONFIG));
}

TEST_F(APIModelTest, sessionCookieSet_returnsFalseWhenSessionCookieFieldEmpty) {
    ASSERT_FALSE(apiModel->sessionCookieSet(this->MOCK_EMPTY_FIELDS_CONFIG));
}

TEST_F(APIModelTest, loginCookie_returnsTrueWhenAccountInfoIsFound) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::BASE)).Times(1);
    EXPECT_CALL(mockCprHelper, setHeader(std::map<std::string, std::string>{{
        REDBetterR::API::Constants::Header::SESSION_COOKIE,
        REDBetterR::API::Constants::Field::SESSION + "=" +
        this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::SESSION_COOKIE)}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(2)
        .WillRepeatedly(Return(MOCK_INDEX_RESPONSE_SUCCESS));
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::AJAX)).Times(1);
    EXPECT_CALL(mockCprHelper, setParameters(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Parameter::ACTION, REDBetterR::API::Constants::Action::INDEX}
    })).Times(1);
    EXPECT_CALL(mockJsonHelper, parse(MOCK_INDEX_RESPONSE_SUCCESS.text)).Times(1)
        .WillOnce(Return(MOCK_INDEX_RESPONSE_SUCCESS_JSON));

    EXPECT_TRUE(this->apiModel->loginCookie(this->MOCK_VALID_CONFIG));
    EXPECT_EQ(this->MOCK_AUTHKEY, this->apiModel->getAuthkey());
    EXPECT_EQ(this->MOCK_PASSKEY, this->apiModel->getPasskey());
    EXPECT_EQ(this->MOCK_USER_ID, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginCookie_returnsFalseWhenResponseIsEmpty) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::BASE)).Times(1);
    EXPECT_CALL(mockCprHelper, setHeader(std::map<std::string, std::string>{{
        REDBetterR::API::Constants::Header::SESSION_COOKIE,
        REDBetterR::API::Constants::Field::SESSION + "=" +
        this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::SESSION_COOKIE)}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(2)
        .WillRepeatedly(Return(MOCK_INDEX_RESPONSE_SUCCESS));
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::AJAX)).Times(1);
    EXPECT_CALL(mockCprHelper, setParameters(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Parameter::ACTION, REDBetterR::API::Constants::Action::INDEX}
    })).Times(1);
    EXPECT_CALL(mockJsonHelper, parse(MOCK_INDEX_RESPONSE_SUCCESS.text)).Times(1)
        .WillOnce(Return(MOCK_EMPTY_JSON));

    EXPECT_FALSE(this->apiModel->loginCookie(this->MOCK_VALID_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginCookie_returnsFalseWhenResponseIsNull) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::BASE)).Times(1);
    EXPECT_CALL(mockCprHelper, setHeader(std::map<std::string, std::string>{{
        REDBetterR::API::Constants::Header::SESSION_COOKIE,
        REDBetterR::API::Constants::Field::SESSION + "=" +
        this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::SESSION_COOKIE)}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(2)
        .WillRepeatedly(Return(MOCK_INDEX_RESPONSE_SUCCESS));
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::AJAX)).Times(1);
    EXPECT_CALL(mockCprHelper, setParameters(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Parameter::ACTION, REDBetterR::API::Constants::Action::INDEX}
    })).Times(1);
    EXPECT_CALL(mockJsonHelper, parse(MOCK_INDEX_RESPONSE_SUCCESS.text)).Times(1)
        .WillOnce(Return(nullptr));

    EXPECT_FALSE(this->apiModel->loginCookie(MOCK_VALID_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginCookie_returnsFalseWhenConfigFieldsEmpty) {
    EXPECT_FALSE(this->apiModel->loginCookie(this->MOCK_EMPTY_FIELDS_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginCookie_returnsFalseWhenConfigIsEmpty) {
    EXPECT_FALSE(this->apiModel->loginCookie(MOCK_EMPTY_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginUsernamePassword_returnsTrueWhenAccountInfoIsFound) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::LOGIN)).Times(1);
    EXPECT_CALL(mockCprHelper, setPayload(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Field::USERNAME, this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::USERNAME)},
        {REDBetterR::API::Constants::Field::PASSWORD, this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::PASSWORD)}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, post()).Times(1);
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::AJAX)).Times(1);
    EXPECT_CALL(mockCprHelper, setParameters(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Parameter::ACTION, REDBetterR::API::Constants::Action::INDEX}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(1)
        .WillRepeatedly(Return(MOCK_INDEX_RESPONSE_SUCCESS));
    EXPECT_CALL(mockJsonHelper, parse(MOCK_INDEX_RESPONSE_SUCCESS.text)).Times(1)
        .WillOnce(Return(MOCK_INDEX_RESPONSE_SUCCESS_JSON));

    EXPECT_TRUE(this->apiModel->loginUsernamePassword(this->MOCK_VALID_CONFIG));
    EXPECT_EQ(this->MOCK_AUTHKEY, this->apiModel->getAuthkey());
    EXPECT_EQ(this->MOCK_PASSKEY, this->apiModel->getPasskey());
    EXPECT_EQ(this->MOCK_USER_ID, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginUsernamePassword_returnsFalseWhenResponseIsEmpty) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::LOGIN)).Times(1);
    EXPECT_CALL(mockCprHelper, setPayload(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Field::USERNAME, this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::USERNAME)},
        {REDBetterR::API::Constants::Field::PASSWORD, this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::PASSWORD)}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, post()).Times(1);
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::AJAX)).Times(1);
    EXPECT_CALL(mockCprHelper, setParameters(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Parameter::ACTION, REDBetterR::API::Constants::Action::INDEX}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(1)
        .WillRepeatedly(Return(MOCK_INDEX_RESPONSE_SUCCESS));
    EXPECT_CALL(mockJsonHelper, parse(MOCK_INDEX_RESPONSE_SUCCESS.text)).Times(1)
        .WillOnce(Return(MOCK_EMPTY_JSON));

    EXPECT_FALSE(this->apiModel->loginUsernamePassword(this->MOCK_VALID_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginUsernamePassword_returnsFalseWhenResponseIsNull) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::LOGIN)).Times(1);
    EXPECT_CALL(mockCprHelper, setPayload(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Field::USERNAME, this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::USERNAME)},
        {REDBetterR::API::Constants::Field::PASSWORD, this->MOCK_VALID_CONFIG.at(REDBetterR::API::Constants::Field::PASSWORD)}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, post()).Times(1);
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::API::Constants::URL::AJAX)).Times(1);
    EXPECT_CALL(mockCprHelper, setParameters(std::map<std::string, std::string>{
        {REDBetterR::API::Constants::Parameter::ACTION, REDBetterR::API::Constants::Action::INDEX}
    })).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(1)
        .WillRepeatedly(Return(MOCK_INDEX_RESPONSE_SUCCESS));
    EXPECT_CALL(mockJsonHelper, parse(MOCK_INDEX_RESPONSE_SUCCESS.text)).Times(1)
        .WillOnce(Return(nullptr));

    EXPECT_FALSE(this->apiModel->loginUsernamePassword(this->MOCK_VALID_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginUsernamePassword_returnsFalseWhenConfigFieldsAreEmpty) {
    EXPECT_FALSE(this->apiModel->loginUsernamePassword(this->MOCK_EMPTY_FIELDS_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}

TEST_F(APIModelTest, loginUsernamePassword_returnsFalseWhenConfigIsEmpty) {
    EXPECT_FALSE(this->apiModel->loginUsernamePassword(this->MOCK_EMPTY_CONFIG));
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getAuthkey());
    EXPECT_EQ(this->EMPTY_STRING, this->apiModel->getPasskey());
    EXPECT_EQ(this->ZERO_UNSIGNED_INT, this->apiModel->getUserId());
}
