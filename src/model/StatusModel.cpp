#include "StatusModel.h"

#include "../constants/StatusConstants.h"
#include "../common/CprHelper.h"
#include "../common/JsonHelper.h"


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
