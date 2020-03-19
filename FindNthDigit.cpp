//
// Created by Wanhui on 3/19/20.
//

#include <cmath>
#include "FindNthDigit.h"

int Solution44::findNthDigit(int n) {
    if (n < 0) {
        return -1;
    }

    int digits = 1;
    int base = 9;
    // 计算n的位数digits
    // 同时将n减去不可能的数，
    // 即原n为digits位中的第新n位数
    while (n - base * digits > 0) {
        n -= base * digits;
        base *= 10;
        digits++;
    }

    // 所求数字在number中的位数
    int idx = n % digits;
    int number = 0;

    // 当位数为0时，表示是number-1的最后一位数字
    if (idx == 0) {
        // 计算number = number - 1(概念上)
        number = std::pow(10, digits - 1) + n / digits - 1;

        // 因为是number-1的最后一位，
        // 则取个位数返回
        return number % 10;
    } else {
        number = std::pow(10, digits - 1) + n / digits;

        // 因为idx是number的中间位
        for (int i = idx; i < digits; i++) {
            number /= 10;
        }

        return number % 10;
    }
}
