#ifndef BASE_MODEL
#define BASE_MODEL

#include "BaseModelInterface.h"

namespace REDBetterR {
    class BaseModel : public BaseModelInterface {
    public:
        BaseModel() = default;
        virtual ~BaseModel() = default;
    };
}

#endif // BASE_MODEL