#include "TestCase.h"

#include "../mock-classes/MockAPIModel.h"
#include "../mock-classes/MockAPIView.h"
#include "../../src/controller/APIController.h"

using testing::Return;


class APIControllerTest : public TestCase {
public:
    APIControllerTest() : TestCase() {
        this->mockApiModel = std::make_shared<MockAPIModel>();
        this->mockApiView = std::make_shared<MockAPIView>();
        std::shared_ptr<REDBetterR::API::APIModelInterface> apiModel = this->mockApiModel;
        std::shared_ptr<REDBetterR::API::APIViewInterface> apiView = this->mockApiView;
        this->apiController = std::make_shared<REDBetterR::API::APIController>(apiModel, apiView);
    }

    std::shared_ptr<MockAPIModel> mockApiModel;
    std::shared_ptr<MockAPIView> mockApiView;
    std::shared_ptr<REDBetterR::API::APIController> apiController;

    const std::map<std::string, std::string> MOCK_MAP = std::map<std::string, std::string>();
};

TEST_F(APIControllerTest, login_SuccessfulWhenUsingSessionCookie) {
    EXPECT_CALL(*mockApiModel, sessionCookieSet(MOCK_MAP)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockApiView, displayLoginWithCookie()).Times(1);
    EXPECT_CALL(*mockApiModel, loginCookie(MOCK_MAP)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockApiView, displayLoginSuccessful()).Times(1);

    apiController->login(MOCK_MAP);
}

TEST_F(APIControllerTest, login_SuccessfulWhenUsingUsernameAndPassword) {
    EXPECT_CALL(*mockApiModel, sessionCookieSet(MOCK_MAP)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mockApiView, displayLoginWithUsernamePassword()).Times(1);
    EXPECT_CALL(*mockApiModel, loginUsernamePassword(MOCK_MAP)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockApiView, displayLoginSuccessful()).Times(1);

    apiController->login(MOCK_MAP);
}

TEST_F(APIControllerTest, login_UnsuccessfulWhenUsingSessionCookie) {
    EXPECT_CALL(*mockApiModel, sessionCookieSet(MOCK_MAP)).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mockApiView, displayLoginWithCookie()).Times(1);
    EXPECT_CALL(*mockApiModel, loginCookie(MOCK_MAP)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mockApiView, displayLoginFailed()).Times(1);

    apiController->login(MOCK_MAP);
}

TEST_F(APIControllerTest, login_UnsuccessfulWhenUsingUsernameAndPassword) {
    EXPECT_CALL(*mockApiModel, sessionCookieSet(MOCK_MAP)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mockApiView, displayLoginWithUsernamePassword()).Times(1);
    EXPECT_CALL(*mockApiModel, loginUsernamePassword(MOCK_MAP)).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mockApiView, displayLoginFailed()).Times(1);

    apiController->login(MOCK_MAP);
}
