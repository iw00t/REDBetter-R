cmake_minimum_required(VERSION 3.1)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/controller ${MY_SOURCE_DIR}/common)

# models
set(BaseModel model/BaseModelInterface.h model/BaseModel.h model/BaseModel.cpp)
set(ConfigModel model/ConfigModelInterface.h model/ConfigModel.h model/ConfigModel.cpp)
set(APIModel model/APIModelInterface.h model/APIModel.h model/APIModel.cpp)
set(StatusModel model/StatusModelInterface.h model/StatusModel.h model/StatusModel.cpp)
add_library(Models ${BaseModel} ${ConfigModel} ${APIModel} ${StatusModel})

# views
set(BaseView view/BaseViewInterface.h view/BaseView.h view/BaseView.cpp)
set(ConfigView view/ConfigViewInterface.h view/ConfigView.h view/ConfigView.cpp)
set(APIView view/APIViewInterface.h view/APIView.h view/APIView.cpp)
set(StatusView view/StatusViewInterface.h view/StatusView.h view/StatusView.cpp)
add_library(Views ${BaseView} ${ConfigView} ${APIView} ${StatusView})

# controllers
set(BaseController controller/BaseControllerInterface.h controller/BaseController.h controller/BaseController.cpp)
set(ConfigController controller/ConfigControllerInterface.h controller/ConfigController.h controller/ConfigController.cpp)
set(APIController controller/APIControllerInterface.h controller/APIController.h controller/APIController.cpp)
set(StatusController controller/StatusControllerInterface.h controller/StatusController.h controller/StatusController.cpp)
add_library(Controllers ${BaseController} ${ConfigController} ${APIController} ${StatusController})

# common
set(CprHelper common/CprHelperInterface.h common/CprHelper.h common/CprHelper.cpp)
set(JsonHelper common/JsonHelperInterface.h common/JsonHelper.h common/JsonHelper.cpp)
add_library(Common ${CprHelper} ${JsonHelper})

# constants
set(APIConstants constants/APIConstants.h constants/APIConstants.cpp)
set(ConfigConstants constants/ConfigConstants.h constants/ConfigConstants.cpp)
set(StatusConstants constants/StatusConstants.h constants/StatusConstants.cpp)
add_library(Constants ${APIConstants} ${ConfigConstants} ${StatusConstants})

include_directories(. ../opt/)

add_executable(REDBetter-R main.cpp)
target_link_libraries(REDBetter-R Controllers Models Views Common Constants ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})
