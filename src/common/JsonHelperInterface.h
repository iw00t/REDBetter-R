#ifndef JSON_HELPER_INTERFACE
#define JSON_HELPER_INTERFACE

#include "../../opt/json.hpp"

#include <string>


namespace REDBetterR {
    namespace Common {
        class JsonHelperInterface {
        public:
            virtual nlohmann::json parse(const std::string &) const = 0;
        };
    }
}

#endif // JSON_HELPER_INTERFACE
