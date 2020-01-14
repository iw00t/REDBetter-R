#include "StatusModel.h"

#include "../common/constants/StatusConstants.h"


namespace REDBetterR {
    namespace Status {
        StatusModel::StatusModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper, std::shared_ptr<Common::JsonHelperInterface> & jsonHelper) : BaseModel(cprHelper, jsonHelper) {}

        nlohmann::json StatusModel::getStatus() const {
            this->getCprHelper()->setUrl(Constants::URL::RED_TRACKER_STATUS_ALL);
            auto statusGet = this->getCprHelper()->get();
            return this->getJsonHelper()->parse(statusGet.text);
        }
    }
}
