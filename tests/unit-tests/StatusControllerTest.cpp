#include "TestCase.h"

#include "../mock-classes/MockStatusModel.h"
#include "../mock-classes/MockStatusView.h"
#include "../../src/controller/StatusController.h"

using testing::Return;


class StatusControllerTest : public TestCase {
public:
    StatusControllerTest() : TestCase() {
        this->statusController = new REDBetterR::Status::StatusController(this->mockStatusModel, this->mockStatusView);
    }

    MockStatusModel mockStatusModel;
    MockStatusView mockStatusView;
    REDBetterR::Status::StatusController* statusController;

    nlohmann::json MOCK_STATUS_JSON = "{}";
};

TEST_F(StatusControllerTest, getStatus) {
    EXPECT_CALL(mockStatusModel, getStatus()).Times(1).WillOnce(Return(MOCK_STATUS_JSON));
    EXPECT_CALL(mockStatusView, displayStatus(MOCK_STATUS_JSON)).Times(1);

    this->statusController->status();
}
