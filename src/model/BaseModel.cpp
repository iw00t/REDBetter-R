#include "BaseModel.h"


namespace REDBetterR {
    BaseModel::BaseModel(Common::CprHelperInterface & cprHelper, Common::JsonHelperInterface & jsonHelper) {
        this->cprHelper = &cprHelper;
        this->jsonHelper = &jsonHelper;
    }

    BaseModel::BaseModel(Common::CprHelperInterface & cprHelper) {
        this->cprHelper = &cprHelper;
    }

    BaseModel::BaseModel(Common::JsonHelperInterface & jsonHelper) {
        this->jsonHelper = &jsonHelper;
    }

    Common::CprHelperInterface* BaseModel::getCprHelper() const {
        return dynamic_cast<Common::CprHelperInterface*>(this->cprHelper);
    }

    Common::JsonHelperInterface* BaseModel::getJsonHelper() const {
        return dynamic_cast<Common::JsonHelperInterface*>(this->jsonHelper);
    }
}
