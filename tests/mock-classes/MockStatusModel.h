#ifndef MOCK_STATUS_MODEL
#define MOCK_STATUS_MODEL

#include "gmock/gmock.h"

#include "../../src/model/StatusModelInterface.h"


class MockStatusModel : public REDBetterR::Status::StatusModelInterface {
public:
    MOCK_CONST_METHOD0(getStatus, nlohmann::json());
};

#endif // MOCK_STATUS_MODEL
