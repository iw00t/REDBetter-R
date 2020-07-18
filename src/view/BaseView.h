#ifndef BASE_VIEW
#define BASE_VIEW

#include "BaseViewInterface.h"


namespace REDBetterR {
    class BaseView : public BaseViewInterface {
    public:
        BaseView() = default;
        virtual ~BaseView() = default;

    protected:
        void displaySpacer() const;
    };
}

#endif // BASE_VIEW
