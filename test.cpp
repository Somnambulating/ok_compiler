#include <gtest/gtest.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h> 
#include <string>

#include "include/caculator.h"

MyCaculator myCaculator;

TEST(MyCaculator, test0) {
    EXPECT_EQ(myCaculator.caculator(std::string("1+1")), 2);  
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}