#include "ConfigConstants.h"


namespace REDBetterR {
    namespace Config {
        namespace Constants {
            const std::string File::FILE_PATH = "../config.json";

            const std::vector<std::string> JSON::JSON_FIELDS = {
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
            const std::vector<std::string> JSON::REQUIRED_JSON_FIELDS = {
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
