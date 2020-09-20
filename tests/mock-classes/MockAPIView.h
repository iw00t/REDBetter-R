#ifndef MOCK_API_VIEW
#define MOCK_API_VIEW

#include "gmock/gmock.h"

#include "../../src/view/APIViewInterface.h"


class MockAPIView : public REDBetterR::API::APIViewInterface {
public:
    MOCK_CONST_METHOD0(displayLoginWithCookie, void());
    MOCK_CONST_METHOD0(displayLoginWithUsernamePassword, void());
    MOCK_CONST_METHOD0(displayLoginSuccessful, void());
    MOCK_CONST_METHOD0(displayLoginFailed, void());
    MOCK_CONST_METHOD1(displayUserInfo, void(const nlohmann::json &));
    MOCK_CONST_METHOD0(displayObtainingSnatchedTorrents, void());
    MOCK_CONST_METHOD2(displayObtainingTranscodeCandidates, void(int current, int total));
};

#endif // MOCK_API_VIEW
