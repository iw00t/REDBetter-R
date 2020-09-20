#ifndef BASE_VO
#define BASE_VO

#include "VOBuilder.h"


namespace REDBetterR {
    namespace VO {
        template <typename T>
        class BaseVO : public VOBuilder<T> {
        public:
            T& id(std::string id) {
                this->idValue = id;
                return static_cast<T&>(*this);
            }

            std::string getId() {
                return this->idValue;
            }

        private:
            std::string idValue;
        };
    }
}

#endif // BASE_VO
