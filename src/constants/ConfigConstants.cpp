#ifndef CONFIG_CONSTANTS
#define CONFIG_CONSTANTS

#include <vector>
#include <string>

namespace REDBetterR {
    namespace Config {
        namespace Constants {
            const std::string FILE_PATH = "../config.json";
            const std::vector<std::string> JSON_FIELDS = {
                "username",
                "password",
                "session_cookie",
                "data_dir",
                "output_dir",
                "torrent_dir",
                "formats",
                "media",
                "24bit_behaviour",
                "piece_length"
            };
            const std::vector<std::string> REQUIRED_JSON_FIELDS = {
                "username",
                "password",
                "data_dir",
                "output_dir",
                "torrent_dir",
                "formats",
                "media",
                "24bit_behaviour",
                "piece_length"
            };
        }
    }
}

#endif //CONFIG_CONSTANTS
