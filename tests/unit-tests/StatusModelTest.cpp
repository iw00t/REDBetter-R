#include "TestCase.h"
#include "../../src/model/StatusModel.h"
#include "../../src/common/constants/StatusConstants.h"
#include "../mock-classes/MockCprHelper.h"
#include "../mock-classes/MockJsonHelper.h"


class StatusModelTest : public TestCase {
public:
    StatusModelTest() : TestCase() {
        this->statusModel = new REDBetterR::Status::StatusModel(this->mockCprHelper, this->mockJsonHelper);
    }

    MockCprHelper mockCprHelper;
    MockJsonHelper mockJsonHelper;
    REDBetterR::Status::StatusModel* statusModel;

    cpr::Response MOCK_CPR_RESPONSE = cpr::Response();
    nlohmann::json MOCK_STATUS_JSON = "{}";
};

TEST_F(StatusModelTest, getStatus) {
    EXPECT_CALL(mockCprHelper, setUrl(REDBetterR::Status::Constants::URL::RED_TRACKER_STATUS_ALL)).Times(1);
    EXPECT_CALL(mockCprHelper, get()).Times(1).WillOnce(Return(MOCK_CPR_RESPONSE));
    EXPECT_CALL(mockJsonHelper, parse(MOCK_CPR_RESPONSE.text)).Times(1).WillOnce(Return(MOCK_STATUS_JSON));

    EXPECT_EQ(MOCK_STATUS_JSON, this->statusModel->getStatus());
}
