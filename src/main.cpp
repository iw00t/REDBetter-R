#include "../headers/APIModel.h"
#include "../headers/APIView.h"
#include "../headers/APIController.h"

int main() {
    APIModel apiModel;
    APIView apiView;

    APIController apiController(apiModel, apiView);

    apiController.loadConfig();
}