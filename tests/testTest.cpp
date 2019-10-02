//
// Created by Makiah Bennett on 10/2/19.
//

#include "gtest/gtest.h"
#include "../src/test.h"

TEST(TestTest, FirstTest) {
    EXPECT_EQ(true, test());
}

TEST(TestTest, SecondTest) {
    EXPECT_EQ(false, test2());
}