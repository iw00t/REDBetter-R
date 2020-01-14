#ifndef BASE_CONTROLLER
#define BASE_CONTROLLER

#include "BaseControllerInterface.h"
#include "../model/BaseModelInterface.h"
#include "../view/BaseViewInterface.h"

namespace REDBetterR {
    class BaseController : public BaseControllerInterface {
    public:
        BaseController() = default;
        explicit BaseController(std::shared_ptr<BaseModelInterface> model, std::shared_ptr<BaseViewInterface> view);
        virtual ~BaseController() = default;
        void setModel(std::shared_ptr<BaseModelInterface> model);
        void setView(std::shared_ptr<BaseViewInterface> view);
        std::shared_ptr<BaseModelInterface> getModel() const;
        std::shared_ptr<BaseViewInterface> getView() const;
    private:
        std::shared_ptr<BaseModelInterface> model;
        std::shared_ptr<BaseViewInterface> view;
    };
}

#endif // BASE_CONTROLLER
