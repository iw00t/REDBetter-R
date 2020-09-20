#ifndef COMMON_CONSTANTS
#define COMMON_CONSTANTS

#include <string>
#include <map>


namespace REDBetterR {
    namespace Common {
        namespace Constants {
            const std::map<std::string, std::map<std::string, std::string>> FORMATS = {
                {
                    "FLAC", {
                        "format", "FLAC",
                        "encoding", "Lossless"
                    }
                },
                {
                    "V0", {
                        "format", "MP3",
                        "encoding", "V0 (VBR)"
                    }
                },
                {
                    "320", {
                        "format", "MP3",
                        "encoding", "320"
                    }
                },
                {
                    "V2", {
                        "format", "MP3",
                        "encoding", "V2 (VBR)"
                    }
                }
            };
        }
    }
}

#endif // COMMON_CONSTANTS
