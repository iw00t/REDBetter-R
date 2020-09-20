#ifndef CPR_HELPER
#define CPR_HELPER

#include "CprHelperInterface.h"

#include <cpr/cpr.h>
#include <string>
#include <map>


namespace REDBetterR {
    namespace Common {
        class CprHelper : public CprHelperInterface {
        public:
            void setUrl(const std::string & url);
            void setHeader(const std::map<std::string, std::string> & header);
            void setPayload(const std::map<std::string, std::string> & payloads);
            void setParameters(const std::map<std::string, std::string> & parameters);
            void setVerifySsl(bool verifySsl);
            cpr::Response get();
            cpr::Response post();

        private:
            cpr::Session* session = new cpr::Session();
            unsigned long long lastRequestTime;

            void setLastRequestTime();
            void rateLimit();
            unsigned long long getCurrentTime() const;
        };
    }
}

#endif // CPR_HELPER
