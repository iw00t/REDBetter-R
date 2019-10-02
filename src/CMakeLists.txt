cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/controller)

# models
set(ConfigModel model/ConfigModel.h model/ConfigModel.cpp)
set(APIModel model/APIModel.h model/APIModel.cpp)
add_library(Models ${ConfigModel} ${APIModel})

# views
set(ConfigView view/ConfigView.h view/ConfigView.cpp)
set(APIView view/APIView.h view/APIView.cpp)
add_library(Views ${ConfigView} ${APIView})

# controllers
set(ConfigController controller/ConfigController.h controller/ConfigController.cpp)
set(APIController controller/APIController.h controller/APIController.cpp)
add_library(Controllers ${ConfigController} ${APIController})

include_directories(. ../opt/)

add_executable(REDBetter-R main.cpp ../opt/json.hpp)
target_link_libraries(REDBetter-R Controllers Models Views ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})
