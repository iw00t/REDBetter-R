#ifndef CONTROLLER_FACTORY
#define CONTROLLER_FACTORY

#include "ControllerFactoryInterface.h"
#include "../../controller/BaseController.h"

#include <string>


namespace REDBetterR {
    namespace Factory {
        class ControllerFactory : public ControllerFactoryInterface {
        public:
            static std::shared_ptr<BaseController> create(const std::string & type);
        };
    }
}

#endif // CONTROLLER_FACTORY
