#include "CprHelper.h"


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

        cpr::Response CprHelper::get() const {
            return this->session->Get();
        }

        cpr::Response CprHelper::post() const {
            return this->session->Post();
        }
    }
}
