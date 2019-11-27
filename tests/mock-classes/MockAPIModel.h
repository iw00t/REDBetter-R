#ifndef MOCK_API_MODEL
#define MOCK_API_MODEL

#include "gmock/gmock.h"

#include "../../src/model/APIModelInterface.h"


class MockAPIModel : public REDBetterR::API::APIModelInterface {
public:
    MOCK_METHOD1(sessionCookieSet, bool(const std::map<std::string, std::string> &));
    MOCK_METHOD1(loginCookie, bool(const std::map<std::string, std::string> &));
    MOCK_METHOD1(loginUsernamePassword, bool(const std::map<std::string, std::string> &));
    MOCK_CONST_METHOD0(getUserInfo, nlohmann::json());
};

#endif // MOCK_API_MODEL
