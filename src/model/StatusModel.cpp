#include "StatusModel.h"

#include "../common/constants/StatusConstants.h"
#include "../common/helper/CprHelper.h"
#include "../common/helper/JsonHelper.h"


namespace REDBetterR {
    namespace Status {
        StatusModel::StatusModel(Common::CprHelperInterface & cprHelper, Common::JsonHelperInterface & jsonHelper) : BaseModel(cprHelper, jsonHelper) {}

        nlohmann::json StatusModel::getStatus() const {
            this->getCprHelper()->setUrl(Constants::URL::RED_TRACKER_STATUS_ALL);
            auto statusGet = this->getCprHelper()->get();
            return this->getJsonHelper()->parse(statusGet.text);
        }
    }
}
