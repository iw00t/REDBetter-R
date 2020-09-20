#ifndef API_MODEL
#define API_MODEL

#include "BaseModel.h"
#include "APIModelInterface.h"

#include <string>
#include <map>

namespace REDBetterR {
    namespace API {
        class APIModel : public BaseModel, public APIModelInterface {
        public:
            APIModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper, std::shared_ptr<Common::JsonHelperInterface> & jsonHelper);
            bool sessionCookieSet(const std::map<std::string, std::string> & config);
            bool loginCookie(const std::map<std::string, std::string> & config);
            bool loginUsernamePassword(const std::map<std::string, std::string> & config);
            nlohmann::json getUserInfo();
            std::map<std::string, std::string> getSnatched();
            VO::ReleaseVO getReleaseInfo(const std::pair<std::string, std::string> & snatchedTorrents);

            std::string getAuthkey() const;
            void setAuthkey(const std::string & authkey);
            std::string getPasskey() const;
            void setPasskey(const std::string & passkey);
            unsigned int getUserId() const;
            void setUserId(unsigned int userId);

        private:
            std::string authkey;
            std::string passkey;
            unsigned int userId = 0;

            nlohmann::json getGroupInfo(const std::string & groupId);
            nlohmann::json getTorrentInfo(const nlohmann::json & torrentInfo) const;
            std::string getArtist(const nlohmann::json & artistsArray) const;
            std::string getYear(const std::string & remasterYear, const std::string & groupYear) const;
            nlohmann::json doAPIRequest(const std::string & action, const std::map<std::string, std::string> & additionalParameters = std::map<std::string, std::string>());
            std::string doHTMLRequest(const std::string & url, const std::map<std::string, std::string> & parameters);
        };
    }
}

#endif //API_MODEL
