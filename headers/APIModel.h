#ifndef API_MODEL
#define API_MODEL

#include "../lib/json.hpp"
#include <string>

class APIModel {
public:
    APIModel() {}
    ~APIModel() {}
    bool checkConfigExists();
    void generateConfigFile();
    bool checkConfigFields();

private:
    std::string FILE_PATH = "config.json";
    std::string username;
    std::string password;
    std::string sessionCookie;
    std::string authkey;
    std::string passkey;
    std::string userId;
    std::string tracker;
    std::string lastRequest;
    std::string rateLimit;
    bool jsonKeyExists(const nlohmann::json & j, const std::string & key);
};

#endif //API_MODEL
