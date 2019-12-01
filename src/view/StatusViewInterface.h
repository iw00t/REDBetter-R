#ifndef STATUS_VIEW_INTERFACE
#define STATUS_VIEW_INTERFACE

#include "BaseViewInterface.h"

#include "../../opt/json.hpp"


namespace REDBetterR {
    namespace Status {
        class StatusViewInterface : public BaseViewInterface {
        public:
            ~StatusViewInterface() override = default;
            virtual void displayStatus(const nlohmann::json & status) const = 0;
        };
    }
}

#endif // STATUS_VIEW_INTERFACE