#include "StatusTestConstants.h"


namespace REDBetterR {
    namespace StatusTest {
        namespace Constants {
            const std::string URL::RED_TRACKER_STATUS_ALL = "https://red.trackerstatus.info/api/all/";

            const std::unordered_map<std::string, std::string> JSON::SERVICES = {
                {"Website", "Website"},
                {"Tracker (HTTP)", "TrackerHTTP"},
                {"Tracker (HTTPS)", "TrackerHTTPS"},
                {"IRC", "IRC"},
                {"IRC (Torrent Announcer)", "IRCTorrentAnnouncer"},
                {"IRC (User Identifier)", "IRCUserIdentifier"}
            };
            const std::string JSON::STATUS = "Status";
            const std::string JSON::LATENCY = "Latency";

            const std::string Online::OFFLINE_STATUS_VALUE = "0";
            const std::string Online::OFFLINE_STATUS_DISPLAY = "Offline";
            const std::string Online::ONLINE_STATUS_VALUE = "1";
            const std::string Online::ONLINE_STATUS_DISPLAY = "Online";
            const std::string Online::UNSTABLE_STATUS_VALUE = "2";
            const std::string Online::UNSTABLE_STATUS_DISPLAY = "Unstable";
            const std::string Online::UNKNOWN_STATUS_DISPLAY = "Unknown";

            const int Output::SPACING = 23;
        }
    }
}
