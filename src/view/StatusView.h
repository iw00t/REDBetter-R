#ifndef STATUS_VIEW
#define STATUS_VIEW

#include "BaseView.h"
#include "StatusViewInterface.h"


namespace REDBetterR {
    namespace Status {
        class StatusView : public BaseView, public StatusViewInterface {
        public:
            void displayStatus(const nlohmann::json & status) const;
        private:
            void displayServiceStatus(const nlohmann::json & status) const;
            void displayStatusBanner() const;
        };
    }
}

#endif // STATUS_VIEW