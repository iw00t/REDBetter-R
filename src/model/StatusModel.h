#ifndef STATUS_MODEL
#define STATUS_MODEL

#include "BaseModel.h"
#include "StatusModelInterface.h"
#include "../common/CprHelperInterface.h"
#include "../common/JsonHelperInterface.h"


namespace REDBetterR {
    namespace Status {
        class StatusModel : public BaseModel, public StatusModelInterface {
        public:
            StatusModel(Common::CprHelperInterface & cprHelper, Common::JsonHelperInterface & jsonHelper);
            nlohmann::json getStatus() const;
        };
    }
}

#endif // STATUS_MODEL
