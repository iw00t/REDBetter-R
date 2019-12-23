#include "JsonHelper.h"


namespace REDBetterR {
    namespace Common {
        nlohmann::json JsonHelper::parse(const std::string & text) const {
            return nlohmann::json::parse(text);
        }
    }
}
