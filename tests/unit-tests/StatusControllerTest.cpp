#include "TestCase.h"

#include "../mock-classes/MockStatusModel.h"
#include "../mock-classes/MockStatusView.h"
#include "../../src/controller/StatusController.h"

using testing::Return;


class StatusControllerTest : public TestCase {
public:
    StatusControllerTest() : TestCase() {
        this->mockStatusModel = std::make_shared<MockStatusModel>();
        this->mockStatusView = std::make_shared<MockStatusView>();
        std::shared_ptr<REDBetterR::Status::StatusModelInterface> statusModel = this->mockStatusModel;
        std::shared_ptr<REDBetterR::Status::StatusViewInterface> statusView = this->mockStatusView;
        this->statusController = std::make_shared<REDBetterR::Status::StatusController>(statusModel, statusView);
    }

    std::shared_ptr<MockStatusModel> mockStatusModel;
    std::shared_ptr<MockStatusView> mockStatusView;
    std::shared_ptr<REDBetterR::Status::StatusController> statusController;

    nlohmann::json MOCK_STATUS_JSON = "{}";
};

TEST_F(StatusControllerTest, getStatus) {
    EXPECT_CALL(*mockStatusModel, getStatus()).Times(1).WillOnce(Return(MOCK_STATUS_JSON));
    EXPECT_CALL(*mockStatusView, displayStatus(MOCK_STATUS_JSON)).Times(1);

    this->statusController->status();
}
