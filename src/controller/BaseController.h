#ifndef BASE_CONTROLLER
#define BASE_CONTROLLER

#include "BaseControllerInterface.h"
#include "../model/BaseModel.h"
#include "../model/BaseModelInterface.h"
#include "../view/BaseView.h"
#include "../view/BaseViewInterface.h"

namespace REDBetterR {
    class BaseController : public BaseControllerInterface {
    public:
        BaseController() = default;
        explicit BaseController(BaseModelInterface & model, BaseViewInterface & view);
        virtual ~BaseController() = default;
        void setModel(BaseModelInterface & model);
        void setView(BaseViewInterface & view);
        BaseModelInterface* getModel() const;
        BaseViewInterface* getView() const;
    private:
        BaseModelInterface* model;
        BaseViewInterface* view;
    };
}

#endif // BASE_CONTROLLER
