cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/controller)

# models
set(APIModel model/APIModel.h model/APIModel.cpp)
add_library(Models ${APIModel})

# views
set(APIView view/APIView.h view/APIView.cpp)
add_library(Views ${APIView})

# controllers
set(APIController controller/APIController.h controller/APIController.cpp)
add_library(Controllers ${APIController})

include_directories(. ../includes/)

add_executable(REDBetter-R main.cpp ../includes/json.hpp)
target_link_libraries(REDBetter-R Controllers Models Views)
