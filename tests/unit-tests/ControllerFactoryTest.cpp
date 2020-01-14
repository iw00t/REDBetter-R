#include "TestCase.h"
#include <typeinfo>

#include "../../src/common/factory/ControllerFactory.h"

using testing::Return;


class ControllerFactoryTest : public TestCase {
public:
    ControllerFactoryTest() : TestCase() {}

    template<typename Base, typename T>
    inline bool instanceOf(const T*) {
        return std::is_base_of<Base, T>::value;
    }
};

TEST_F(ControllerFactoryTest, CanConstructAPIController) {
    auto apiController = std::dynamic_pointer_cast<REDBetterR::API::APIController>(REDBetterR::Factory::ControllerFactory::create(REDBetterR::API::Constants::NAME));

    EXPECT_FALSE(apiController == nullptr);
}

TEST_F(ControllerFactoryTest, CanConstructConfigController) {
    auto configController = std::dynamic_pointer_cast<REDBetterR::Config::ConfigController>(REDBetterR::Factory::ControllerFactory::create(REDBetterR::Config::Constants::NAME));

    EXPECT_FALSE(configController == nullptr);
}

TEST_F(ControllerFactoryTest, CanContructStatusController) {
    auto statusController = std::dynamic_pointer_cast<REDBetterR::Status::StatusController>(REDBetterR::Factory::ControllerFactory::create(REDBetterR::Status::Constants::NAME));

    EXPECT_FALSE(statusController == nullptr);
}
