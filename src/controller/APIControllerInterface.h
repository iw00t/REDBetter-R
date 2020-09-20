#ifndef API_CONTROLLER_INTERFACE
#define API_CONTROLLER_INTERFACE

#include "BaseControllerInterface.h"
#include "../model/APIModel.h"
#include "../view/APIView.h"

#include <map>

namespace REDBetterR {
    namespace API {
        class APIControllerInterface : public BaseControllerInterface {
        public:
            ~APIControllerInterface() override = default;
            virtual void login(const std::map<std::string, std::string> &) = 0;
            virtual std::vector<VO::ReleaseVO> getTranscodeCandidates() = 0;
        };
    }
}

#endif //API_CONTROLLER_INTERFACE
