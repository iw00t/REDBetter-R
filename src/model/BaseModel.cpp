#include "BaseModel.h"


namespace REDBetterR {
    BaseModel::BaseModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper, std::shared_ptr<Common::JsonHelperInterface> & jsonHelper) {
        this->cprHelper = cprHelper;
        this->jsonHelper = jsonHelper;
        this->getCprHelper()->setVerifySsl(false);
    }

    BaseModel::BaseModel(std::shared_ptr<Common::CprHelperInterface> & cprHelper) {
        this->cprHelper = cprHelper;
    }

    BaseModel::BaseModel(std::shared_ptr<Common::JsonHelperInterface> & jsonHelper) {
        this->jsonHelper = jsonHelper;
    }

    std::shared_ptr<Common::CprHelperInterface> BaseModel::getCprHelper() const {
        return this->cprHelper;
    }

    std::shared_ptr<Common::JsonHelperInterface> BaseModel::getJsonHelper() const {
        return this->jsonHelper;
    }
}
