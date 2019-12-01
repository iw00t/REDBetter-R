#ifndef MOCK_JSON_WRAPPER
#define MOCK_JSON_WRAPPER

#include "gmock/gmock.h"

#include "../../src/common/JsonHelperInterface.h"


class MockJsonHelper : public REDBetterR::Common::JsonHelperInterface {
public:
    MOCK_CONST_METHOD1(parse, nlohmann::json(const std::string &));
};

#endif // MOCK_JSON_WRAPPER
