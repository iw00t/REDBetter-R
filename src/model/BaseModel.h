#ifndef BASE_MODEL
#define BASE_MODEL

#include "BaseModelInterface.h"

#include "../common/helper/CprHelperInterface.h"
#include "../common/helper/JsonHelperInterface.h"


namespace REDBetterR {
    class BaseModel : public BaseModelInterface {
    public:
        BaseModel() = default;
        explicit BaseModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper, std::shared_ptr<Common::JsonHelperInterface> & jsonHelper);
        explicit BaseModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper);
        explicit BaseModel(std::shared_ptr<Common::JsonHelperInterface> & jsonHelper);
        virtual ~BaseModel() = default;
        std::shared_ptr<Common::CprHelperInterface> getCprHelper() const;
        std::shared_ptr<Common::JsonHelperInterface> getJsonHelper() const;
    private:
        std::shared_ptr<Common::CprHelperInterface> cprHelper;
        std::shared_ptr<Common::JsonHelperInterface> jsonHelper;
    };
}

#endif // BASE_MODEL
