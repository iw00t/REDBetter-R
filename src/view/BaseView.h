#ifndef BASE_VIEW
#define BASE_VIEW

namespace REDBetterR {
    class BaseView {
    public:
        BaseView() = default;
        virtual ~BaseView() = default;

    protected:
        void displaySpacer() const;
    };
}

#endif // BASE_VIEW