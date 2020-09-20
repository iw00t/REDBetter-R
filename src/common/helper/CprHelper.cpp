#include "CprHelper.h"
#include <iostream>


namespace REDBetterR {
    namespace Common {
        void CprHelper::setUrl(const std::string & url) {
            this->session->SetUrl(url);
        }

        void CprHelper::setHeader(const std::map<std::string, std::string> & header) {
            cpr::Header cprHeader;
            for (const auto & headerItem : header) {
                cprHeader.insert(headerItem);
            }
            this->session->SetHeader(cprHeader);
        }

        void CprHelper::setPayload(const std::map<std::string, std::string> & payloads) {
            cpr::Payload cprPayload = {};
            for (const auto & payload : payloads) {
                cprPayload.AddPair(cpr::Pair(payload.first, payload.second));
            }
            this->session->SetPayload(cprPayload);
        }

        void CprHelper::setParameters(const std::map<std::string, std::string> & parameters) {
            cpr::Parameters cprParameters;
            for (const auto & parameter : parameters) {
                cprParameters.AddParameter(cpr::Parameter(parameter.first, parameter.second));
            }
            this->session->SetParameters(cprParameters);
        }

        void CprHelper::setVerifySsl(bool verifySsl) {
            this->session->SetVerifySsl(verifySsl);
        }

        cpr::Response CprHelper::get() {
            cpr::Response response = this->session->Get();
            this->rateLimit();
            this->setLastRequestTime();
            return response;
        }

        cpr::Response CprHelper::post() {
            cpr::Response response = this->session->Post();
            this->rateLimit();
            this->setLastRequestTime();
            return response;
        }

        void CprHelper::setLastRequestTime() {
            this->lastRequestTime = this->getCurrentTime();
        }

        void CprHelper::rateLimit() {
            unsigned long long currentTime = this->getCurrentTime();
            while (currentTime - this->lastRequestTime < 2) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                currentTime = this->getCurrentTime();
            }
        }

        unsigned long long CprHelper::getCurrentTime() const {
            return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
    }
}
