#ifndef TEST_CASE
#define TEST_CASE

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class TestCase : public ::testing::Test{
public:
    TestCase() : Test() {}

    // surpresses console output by redirecting the std::cout stream
    virtual void SetUp() override {
        storedStreambuf_ = std::cout.rdbuf();
        std::cout.rdbuf(nullptr);
    }

    virtual void TearDown() override {
        std::cout.rdbuf(storedStreambuf_);
    }

    std::streambuf* storedStreambuf_;
};

#endif //TEST_CASE