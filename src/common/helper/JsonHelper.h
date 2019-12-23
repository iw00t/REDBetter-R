#ifndef JSON_HELPER
#define JSON_HELPER

#include "JsonHelperInterface.h"

#include "../../../opt/json.hpp"
#include <string>


namespace REDBetterR {
    namespace Common {
        class JsonHelper : public JsonHelperInterface {
        public:
            nlohmann::json parse(const std::string & text) const;
        };
    }
}

#endif // JSON_HELPER
