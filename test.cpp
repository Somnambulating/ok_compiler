#include <gtest/gtest.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h> 
#include <string>

#include "include/caculator.h"

TEST(Caculator, Equal) {
    MyCaculator myCaculator;
    EXPECT_EQ(2, myCaculator.caculator(std::string("1+1")));
    EXPECT_EQ(7, myCaculator.caculator(std::string("1+2*(1+2)")));
    EXPECT_EQ(-1.0, myCaculator.caculator(std::string("1-2*(1+2)/3")));
}

TEST(Caculator, UnEqual) {
    MyCaculator myCaculator;
    EXPECT_NE(2, myCaculator.caculator(std::string("1+3")));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}