#include "model/APIModel.h"
#include "view/APIView.h"
#include "controller/APIController.h"

int main() {
    APIModel apiModel;
    APIView apiView;

    APIController apiController(apiModel, apiView);

    apiController.loadConfig();
}