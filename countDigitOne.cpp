//
// Created by Wanhui on 3/18/20.
//

#include <algorithm>
#include "countDigitOne.h"


int Solution43::countDigitOne(int n) {
    int counter = 0;

    // 通过规律公式计算
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        counter += (n / divider) * i + std::min(std::max(n % divider - i + 1, 0LL), i);
    }

    return counter;
}
