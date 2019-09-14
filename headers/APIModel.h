#ifndef API_MODEL
#define API_MODEL

#include <string>

class APIModel {
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

public:
    APIModel() {}
    ~APIModel() {}
    bool checkConfigExists();
    void generateConfigFile();
};

#endif //API_MODEL
