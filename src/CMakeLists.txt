cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/controller)

# models
set(BaseModel model/BaseModelInterface.h model/BaseModel.h model/BaseModel.cpp)
set(ConfigModel model/ConfigModelInterface.h model/ConfigModel.h model/ConfigModel.cpp)
set(APIModel model/APIModelInterface.h model/APIModel.h model/APIModel.cpp)
add_library(Models ${BaseModel} ${ConfigModel} ${APIModel})

# views
set(BaseView view/BaseViewInterface.h view/BaseView.h view/BaseView.cpp)
set(ConfigView view/ConfigViewInterface.h view/ConfigView.h view/ConfigView.cpp)
set(APIView view/APIViewInterface.h view/APIView.h view/APIView.cpp)
add_library(Views ${BaseView} ${ConfigView} ${APIView})

# controllers
set(BaseController controller/BaseControllerInterface.h controller/BaseController.h controller/BaseController.cpp)
set(ConfigController controller/ConfigControllerInterface.h controller/ConfigController.h controller/ConfigController.cpp)
set(APIController controller/APIControllerInterface.h controller/APIController.h controller/APIController.cpp)
add_library(Controllers ${BaseController} ${ConfigController} ${APIController})

include_directories(. ../opt/)

add_executable(REDBetter-R main.cpp ../opt/json.hpp)
target_link_libraries(REDBetter-R Controllers Models Views ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})
