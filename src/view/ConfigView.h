#ifndef CONFIG_VIEW
#define CONFIG_VIEW

namespace REDBetterR {
    namespace Config {
        class ConfigView {
        public:
            ConfigView() {}
            ~ConfigView() {}
            void displayConfigMissing();
            void displayConfigFieldMissing();
        };
    }
}

#endif // CONFIG_VIEW