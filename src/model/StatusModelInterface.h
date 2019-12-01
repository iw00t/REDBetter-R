#ifndef STATUS_MODEL_INTERFACE
#define STATUS_MODEL_INTERFACE

#include "BaseModelInterface.h"

#include "../../opt/json.hpp"


namespace REDBetterR {
    namespace Status {
        class StatusModelInterface : public BaseModelInterface {
        public:
            ~StatusModelInterface() override = default;
            virtual nlohmann::json getStatus() const = 0;
        };
    }
}

#endif // STATUS_MODEL_INTERFACE
