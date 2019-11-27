#ifndef BASE_CONTROLLER_INTERFACE
#define BASE_CONTROLLER_INTERFACE

#include "../model/BaseModel.h"
#include "../model/BaseModelInterface.h"
#include "../view/BaseView.h"
#include "../view/BaseViewInterface.h"


namespace REDBetterR {
    class BaseControllerInterface {
    public:
        BaseControllerInterface() = default;
        explicit BaseControllerInterface(BaseModelInterface &, BaseViewInterface &);
        virtual ~BaseControllerInterface() = default;
    };
}

#endif // BASE_CONTROLLER_INTERFACE