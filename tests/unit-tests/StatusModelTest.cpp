#include "TestCase.h"
#include "../../src/model/StatusModel.h"
#include "../common/constants/StatusTestConstants.h"
#include "../mock-classes/MockCprHelper.h"
#include "../mock-classes/MockJsonHelper.h"


class StatusModelTest : public TestCase {
public:
    StatusModelTest() : TestCase() {
        this->mockCprHelper = std::make_shared<MockCprHelper>();
        this->mockJsonHelper = std::make_shared<MockJsonHelper>();
        std::shared_ptr<REDBetterR::Common::CprHelperInterface> cprHelper = this->mockCprHelper;
        std::shared_ptr<REDBetterR::Common::JsonHelperInterface> jsonHelper = this->mockJsonHelper;
        EXPECT_CALL(*mockCprHelper, setVerifySsl(REDBetterR::StatusTest::Constants::Metadata::VERIFY_SSL)).Times(1);
        this->statusModel = std::make_shared<REDBetterR::Status::StatusModel>(cprHelper, jsonHelper);
    }

    std::shared_ptr<MockCprHelper> mockCprHelper;
    std::shared_ptr<MockJsonHelper> mockJsonHelper;
    std::shared_ptr<REDBetterR::Status::StatusModel> statusModel;

    cpr::Response MOCK_CPR_RESPONSE = cpr::Response();
    nlohmann::json MOCK_STATUS_JSON = "{}";
};

TEST_F(StatusModelTest, getStatus) {
    EXPECT_CALL(*mockCprHelper, setUrl(REDBetterR::StatusTest::Constants::URL::RED_TRACKER_STATUS_ALL)).Times(1);
    EXPECT_CALL(*mockCprHelper, get()).Times(1).WillOnce(Return(MOCK_CPR_RESPONSE));
    EXPECT_CALL(*mockJsonHelper, parse(MOCK_CPR_RESPONSE.text)).Times(1).WillOnce(Return(MOCK_STATUS_JSON));

    EXPECT_EQ(MOCK_STATUS_JSON, this->statusModel->getStatus());
}
