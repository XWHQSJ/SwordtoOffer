//
// Created by Wanhui on 2/16/20.
//

#include <vector>
#include <iostream>
#include "NumWays.h"

int Solution10_2::numWays(int n) {
    int f = 0;
    if(f > 1000000007) {
        f %= 1000000007;
    }

    if(n == 1) {
        f = 1;
    }

    if(n == 2) {
        f = 2;
    }

    if(n > 2) {
        f = numWays(n-2) + numWays(n-1);
    }

    return f;
}

int Solution10_2::numWays2(int n) {
    std::vector<int> vec = {1, 1};

    for(int i = 2; i <= n; i++){
        vec.push_back((vec[i-2] + vec[i-1])%1000000007);
    }

    return vec[n];
}
