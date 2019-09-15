cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/controller)

# models
set(ConfigModel model/ConfigModel.h model/ConfigModel.cpp)
add_library(Models ${ConfigModel})

# views
set(ConfigView view/ConfigView.h view/ConfigView.cpp)
add_library(Views ${ConfigView})

# controllers
set(ConfigController controller/ConfigController.h controller/ConfigController.cpp)
add_library(Controllers ${ConfigController})

include_directories(. ../includes/)

add_executable(REDBetter-R main.cpp ../includes/json.hpp)
target_link_libraries(REDBetter-R Controllers Models Views)
