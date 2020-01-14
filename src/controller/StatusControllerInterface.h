#ifndef STATUS_CONTROLLER_INTERFACE
#define STATUS_CONTROLLER_INTERFACE

#include "BaseControllerInterface.h"

#include <map>


namespace REDBetterR {
    namespace Status {
        class StatusControllerInterface : public BaseControllerInterface {
        public:
            ~StatusControllerInterface() override = default;
            virtual void status() = 0;
        };
    }
}

#endif // STATUS_CONTROLLER_INTERFACE
