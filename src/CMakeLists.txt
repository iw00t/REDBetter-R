cmake_minimum_required(VERSION 3.1)

include_directories(${MY_SOURCE_DIR}/common ${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/controller)

# common
set(CprHelper common/helper/CprHelperInterface.h common/helper/CprHelper.h common/helper/CprHelper.cpp)
set(JsonHelper common/helper/JsonHelperInterface.h common/helper/JsonHelper.h common/helper/JsonHelper.cpp)
set(CommonConstants common/constants/CommonConstants.h)
set(APIConstants common/constants/APIConstants.h common/constants/APIConstants.cpp)
set(ConfigConstants common/constants/ConfigConstants.h common/constants/ConfigConstants.cpp)
set(StatusConstants common/constants/StatusConstants.h common/constants/StatusConstants.cpp)
set(ControllerFactory common/factory/ControllerFactoryInterface.h common/factory/ControllerFactory.h common/factory/ControllerFactory.cpp)
add_library(Common SHARED ${CprHelper} ${JsonHelper} ${CommonConstants} ${APIConstants} ${ConfigConstants} ${StatusConstants} ${ControllerFactory})

# vo
set(VOs vo/VOBuilder.h vo/BaseVO.h vo/ReleaseVO.h)
add_library(VO SHARED ${VOs})
set_target_properties(VO PROPERTIES LINKER_LANGUAGE CXX)

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

include_directories(. ../opt/)

add_executable(REDBetter-R main.cpp)
target_link_libraries(REDBetter-R Common VO Controllers Models Views ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS})
