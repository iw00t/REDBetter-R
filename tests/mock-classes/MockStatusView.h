#ifndef MOCK_STATUS_VIEW
#define MOCK_STATUS_VIEW

#include "gmock/gmock.h"

#include "../../src/view/StatusViewInterface.h"


class MockStatusView : public REDBetterR::Status::StatusViewInterface {
public:
    MOCK_CONST_METHOD1(displayStatus, void(const nlohmann::json & status));
};

#endif // MOCK_STATUS_VIEW
