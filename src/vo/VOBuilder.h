#ifndef VO_BUILDER
#define VO_BUILDER


namespace REDBetterR {
    namespace VO {
        template <typename T>
        class VOBuilder {
        public:
            static T builder() {
                return {};
            }
            T & build() {
                return static_cast<T&>(*this);
            }
        };
    }
}

#endif // VO_BUILDER
