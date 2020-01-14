#ifndef CONTROLLER_FACTORY_INTERFACE
#define CONTROLLER_FACTORY_INTERFACE

#include "../../controller/BaseController.h"


namespace REDBetterR {
    namespace Factory {
        class ControllerFactoryInterface {
        public:
            static std::shared_ptr<BaseController> create(const std::string &);
        };
    }
}

#endif // CONTROLLER_FACTORY_INTERFACE
