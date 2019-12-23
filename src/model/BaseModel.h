#ifndef BASE_MODEL
#define BASE_MODEL

#include "BaseModelInterface.h"

#include "../common/helper/CprHelperInterface.h"
#include "../common/helper/JsonHelperInterface.h"


namespace REDBetterR {
    class BaseModel : public BaseModelInterface {
    public:
        BaseModel() = default;
        explicit BaseModel(Common::CprHelperInterface & cprHelper, Common::JsonHelperInterface & jsonHelper);
        explicit BaseModel(Common::CprHelperInterface & cprHelper);
        explicit BaseModel(Common::JsonHelperInterface & jsonHelper);
        virtual ~BaseModel() = default;
        Common::CprHelperInterface* getCprHelper() const;
        Common::JsonHelperInterface* getJsonHelper() const;
    private:
        Common::CprHelperInterface* cprHelper;
        Common::JsonHelperInterface* jsonHelper;
    };
}

#endif // BASE_MODEL
