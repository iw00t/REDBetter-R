#ifndef API_CONTROLLER
#define API_CONTROLLER

#include "../model/APIModel.h"
#include "../view/APIView.h"

class APIController {
public:
    APIController(APIModel model, APIView view);
    ~APIController() {}
    void setModel(APIModel model);
    void setView(APIView view);
    void loadConfig();

private:
    APIModel model;
    APIView view;
};

#endif //API_CONTROLLER