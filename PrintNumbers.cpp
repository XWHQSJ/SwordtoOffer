//
// Created by Wanhui on 2/19/20.
//

#include <cmath>
#include <climits>
#include "PrintNumbers.h"


std::vector<int> Solution17::printNumbers(int n) {
    std::vector<int> res;
    int i = 1;

    int m = 1;

    //函数库pow(x,n)
    m = pow(10, n);

    //手动乘
//    while (n>0){
//        m *= 10;
//        n--;
//    }

    if (m > INT_MAX) {
        return {};
    }

    while (i < m) {
        res.push_back(i);
        i++;
    }

    return res;
}

std::vector<LL> Solution17::printNumbers2(LL base, LL a) {
    std::vector<LL> res;
    LL m = 1;
    while (a != 0) {
        //a&1表示判断a的二进制最后一位是否为1
        if (a & 1) {
            //当位数为1时，乘底数
            m *= base;
        }

        //a每移位一次，base乘一倍
        base *= base;
        //右移或a/=2
        a = a >> 1;
    }

    LL i = 1;
    while (i < m) {
        res.push_back(i);
        i++;
    }

    return res;
}

std::vector<LL> Solution17::printNumbersTemplate(LL base, LL a, LL m) {
    std::vector<LL> res;
    LL x = 1;
    while (a != 0) {
        if (a & 1) {
            x = (x * base) % m;
        }
        base = (base * base) % m;
        a = a >> 1;
    }

    LL i = 1;
    while (i < x) {
        res.push_back(i);
        i++;
    }

    return res;
}
