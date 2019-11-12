#ifndef BASE_CONTROLLER
#define BASE_CONTROLLER

#include "../model/BaseModel.h"
#include "../view/BaseView.h"

namespace REDBetterR {
    class BaseController {
    public:
        BaseController(BaseModel & model, BaseView & view);
        virtual ~BaseController() = default;
        void setModel(BaseModel & model);
        void setView(BaseView & view);
        BaseModel* getModel();
        BaseView* getView();
    private:
        BaseModel* model;
        BaseView* view;
    };
}

#endif // BASE_CONTROLLER