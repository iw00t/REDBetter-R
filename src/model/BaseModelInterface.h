#ifndef BASE_MODEL_INTERFACE
#define BASE_MODEL_INTERFACE

#include "../common/helper/CprHelperInterface.h"
#include "../common/helper/JsonHelperInterface.h"


namespace REDBetterR {
    class BaseModelInterface {
    public:
        BaseModelInterface() = default;
        explicit BaseModelInterface(Common::CprHelperInterface &, Common::JsonHelperInterface &);
        explicit BaseModelInterface(Common::CprHelperInterface &);
        explicit BaseModelInterface(Common::JsonHelperInterface &);
        virtual ~BaseModelInterface() = default;
    };
}

#endif // BASE_MODEL_INTERFACE