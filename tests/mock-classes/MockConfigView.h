#ifndef MOCK_CONFIG_VIEW
#define MOCK_CONFIG_VIEW

#include "gmock/gmock.h"

#include "../../src/view/ConfigViewInterface.h"


class MockConfigView : public REDBetterR::Config::ConfigViewInterface {
public:
    MOCK_CONST_METHOD0(displayConfigMissing, void());
    MOCK_CONST_METHOD0(displayConfigFieldMissing, void());
    MOCK_CONST_METHOD1(displayEmptyFields, void(const std::vector<std::string> &));
};

#endif //MOCK_CONFIG_VIEW
