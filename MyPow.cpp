//
// Created by Wanhui on 2/20/20.
//

#include <climits>
#include "MyPow.h"

double Solution16::myPow(double x, int n) {
    double m = 1;

    if (n == 0) {
        return 1;
    }

    // WARNing : abs(INT_MIN) 比 INT_MAX 大1，
    // 所以不能直接使用 n=-n
    if (n == INT_MIN) {
        // 将n右移一位，
        // 这样 n=-n 就不会出错
        n = n >> 1;
        // 因为n右移了一位，
        // 所以 x 需要翻倍
        x = x * x;

        // 这里也可以强制转换为 unsigned int类型进行取反
        // unsigned int a = (unsigned int)n;
    }

    // 当 n<0 时，需要将n取反、x取倒
    if (n < 0) {
        n = -n;
        x = 1 / x;
    }

    while (n != 0) {
        //a&1表示判断a的二进制最后一位是否为1
        if (n & 1) {
            //当位数为1时，乘底数
            m *= x;
        }

        //a每移位一次，base乘一倍
        x *= x;
        //右移或a/=2
        n = n >> 1;
    }

    return m;
}
