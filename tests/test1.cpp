//
// Created by t on 9/28/2019.
//

#include "gtest/gtest.h"

class Blah : public ::testing::Test {

};

TEST(basic_check, test_eq) {
    EXPECT_EQ(1, 1);
}
