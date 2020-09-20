#ifndef MOCK_CPR_HELPER
#define MOCK_CPR_HELPER

#include "gmock/gmock.h"

#include "../../src/common/helper/CprHelperInterface.h"


class MockCprHelper : public REDBetterR::Common::CprHelperInterface {
public:
    MOCK_METHOD1(setUrl, void(const std::string &));
    MOCK_METHOD1(setHeader, void(const std::map<std::string, std::string> &));
    MOCK_METHOD1(setPayload, void(const std::map<std::string, std::string> &));
    MOCK_METHOD1(setParameters, void(const std::map<std::string, std::string> &));
    MOCK_METHOD1(setVerifySsl, void(bool));
    MOCK_METHOD0(get, cpr::Response());
    MOCK_METHOD0(post, cpr::Response());
};

#endif // MOCK_CPR_HELPER
