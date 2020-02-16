//
// Created by Wanhui on 2/16/20.
//

#include <vector>
#include "Fibonacci.h"

int Solution10_1::fibonacci(int n) {
    int f = 0;
    if(f > 1000000007) {
        f %= 1000000007;
    }

    if(n == 0) {
        f = 0;
    }

    if(n == 1) {
        f = 1;
    }

    if(n > 1){
        f = fibonacci(n - 1) + fibonacci(n -2);
    }

    return f;
}

int Solution10_1::fibonacci2(int n) {
    std::vector<int> vec = {0, 1};

    for(int i = 2; i <= n; i++){
        vec.push_back((vec[i-2]+vec[i-1])%1000000007);
    }

    return vec[n];
}
