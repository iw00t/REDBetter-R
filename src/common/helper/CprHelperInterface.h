#ifndef CPR_HELPER_INTERFACE
#define CPR_HELPER_INTERFACE

#include <cpr/cpr.h>
#include <string>
#include <map>


namespace REDBetterR {
    namespace Common {
        class CprHelperInterface {
        public:
            virtual void setUrl(const std::string &) = 0;
            virtual void setHeader(const std::map<std::string, std::string> &) = 0;
            virtual void setPayload(const std::map<std::string, std::string> &) = 0;
            virtual void setParameters(const std::map<std::string, std::string> &) = 0;
            virtual void setVerifySsl(bool) = 0;
            virtual cpr::Response get() = 0;
            virtual cpr::Response post() = 0;
        };
    }
}

#endif // CPR_HELPER_INTERFACE
