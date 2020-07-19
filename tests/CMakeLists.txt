cmake_minimum_required(VERSION 3.1)
project(REDBetter-R_tests)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(APITestConstants common/constants/APITestConstants.h common/constants/APITestConstants.cpp)
set(ConfigTestConstants common/constants/ConfigTestConstants.h common/constants/ConfigTestConstants.cpp)
set(StatusTestConstants common/constants/StatusTestConstants.h common/constants/StatusTestConstants.cpp)
add_library(TestConstants SHARED ${APITestConstants} ${ConfigTestConstants} ${StatusTestConstants})

add_executable(REDBetter-R_tests tests.cpp unit-tests/TestCase.h)
target_link_libraries(REDBetter-R_tests gtest gtest_main gmock gmock_main TestConstants Common Controllers Models Views ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})
