#include "APIConstants.h"


namespace REDBetterR {
    namespace API {
        namespace Constants {
            const bool Metadata::VERIFY_SSL = false;
            const std::map<std::string, std::string> Metadata::HEADER = {
                {"Connection", "keep-alive"},
                {"Cache-Control", "max-age=0"},
                {"User-Agent", "REDBetter-R"},
                {"Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"},
                {"Accept-Encoding", "gzip,deflate,sdch"},
                {"Accept-Language", "en-US,en;q=0.8"},
                {"Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.3"}
            };

            const std::string URL::BASE = "https://redacted.ch/";
            const std::string URL::LOGIN = URL::BASE + "login.php";
            const std::string URL::AJAX = URL::BASE + "ajax.php";
            const std::string URL::TORRENTS = URL::BASE + "torrents.php";

            const std::string Field::USERNAME = "username";
            const std::string Field::PASSWORD = "password";
            const std::string Field::SESSION = "session";
            const std::string Field::RESPONSE = "response";
            const std::string Field::AUTHKEY = "authkey";
            const std::string Field::PASSKEY = "passkey";
            const std::string Field::SESSION_COOKIE = "session_cookie";
            const std::string Field::USER_STATS = "userstats";
            const std::string Field::CLASS = "class";
            const std::string Field::UPLOADED = "uploaded";
            const std::string Field::DOWNLOADED = "downloaded";
            const std::string Field::RATIO = "ratio";
            const std::string Field::REQUIRED_RATIO = "requiredratio";
            const std::string Field::STATUS = "status";
            const std::string Field::ID = "id";

            const std::string Header::SESSION_COOKIE = "Cookie";

            const std::string Response::SUCCESS = "success";

            const std::string Parameter::ACTION = "action";
            const std::string Parameter::AUTH = "auth";
            const std::string Parameter::TYPE = "type";
            const std::string Parameter::SNATCHED = "snatched";
            const std::string Parameter::USERID = "userid";
            const std::string Parameter::FORMAT = "format";
            const std::string Parameter::FLAC = "FLAC";
            const std::string Parameter::PAGE = "page";
            const std::string Parameter::GROUP_ID = "id";

            const std::string Action::INDEX = "index";
            const std::string Action::TORRENT_GROUP = "torrentgroup";
            
            const std::string Output::SPACER = " : ";
            const int Output::SPACING = 14;
        }
    }
}
