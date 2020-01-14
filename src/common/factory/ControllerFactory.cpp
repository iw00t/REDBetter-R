#include "ControllerFactory.h"

#include "common/helper/CprHelper.h"
#include "common/helper/JsonHelper.h"

#include "../constants/APIConstants.h"
#include "../../model/APIModel.h"
#include "../../view/APIView.h"
#include "../../controller/APIController.h"

#include "../constants/ConfigConstants.h"
#include "../../model/ConfigModel.h"
#include "../../view/ConfigView.h"
#include "../../controller/ConfigController.h"

#include "../constants/StatusConstants.h"
#include "../../model/StatusModel.h"
#include "../../view/StatusView.h"
#include "../../controller/StatusController.h"


namespace REDBetterR {
    namespace Factory {
        std::shared_ptr<BaseController> ControllerFactory::create(const std::string & type) {
            if (type == REDBetterR::API::Constants::NAME) {
                std::shared_ptr<REDBetterR::Common::CprHelperInterface> cprHelper = std::make_shared<REDBetterR::Common::CprHelper>();
                std::shared_ptr<REDBetterR::Common::JsonHelperInterface> jsonHelper = std::make_shared<REDBetterR::Common::JsonHelper>();
                std::shared_ptr<REDBetterR::API::APIModelInterface> apiModel = std::make_shared<REDBetterR::API::APIModel>(cprHelper, jsonHelper);
                std::shared_ptr<REDBetterR::API::APIViewInterface> apiView = std::make_shared<REDBetterR::API::APIView>();
                return std::make_shared<REDBetterR::API::APIController>(apiModel, apiView);
            } else if (type == REDBetterR::Config::Constants::NAME) {
                std::shared_ptr<REDBetterR::Config::ConfigModelInterface> configModel = std::make_shared<REDBetterR::Config::ConfigModel>();
                std::shared_ptr<REDBetterR::Config::ConfigViewInterface> configView = std::make_shared<REDBetterR::Config::ConfigView>();
                return std::make_shared<REDBetterR::Config::ConfigController>(configModel, configView);
            } else if (type == REDBetterR::Status::Constants::NAME) {
                std::shared_ptr<REDBetterR::Common::CprHelperInterface> cprHelper = std::make_shared<REDBetterR::Common::CprHelper>();
                std::shared_ptr<REDBetterR::Common::JsonHelperInterface> jsonHelper = std::make_shared<REDBetterR::Common::JsonHelper>();
                std::shared_ptr<REDBetterR::Status::StatusModelInterface> statusModel = std::make_shared<REDBetterR::Status::StatusModel>(cprHelper, jsonHelper);
                std::shared_ptr<REDBetterR::Status::StatusViewInterface> statusView = std::make_shared<REDBetterR::Status::StatusView>();
                return std::make_shared<REDBetterR::Status::StatusController>(statusModel, statusView);
            }
            return nullptr;
        }
    }
}
