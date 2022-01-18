#include <iostream>
#include <stdlib.h>
#include <ctype.h> 

#include "include/caculator.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        LOGE << "unvalid parameters.\n";
        exit(-1);
    }

    // LOGI << "The result of " << argv[1] << "\n";

    MyCaculator myCaculator;
    double result = myCaculator.caculator(argv[1]);
    LOGI << "The result of " << argv[1] << " is " << result << "\n";

    return 0;
}