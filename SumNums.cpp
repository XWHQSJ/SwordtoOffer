//
// Created by Wanhui on 3/10/20.
//

#include <cmath>
#include "SumNums.h"

int Solution64::sumNums(int n) {
    // 构造A && B
    // A : n > 0是终止条件
    // B : (n += sumNums(n-1) > 0)是计算式子
    n > 0 && ((n += sumNums(n-1)) > 0);

    return n;
}


int Solution64::sumNums2(int n) {
    return ((int)(std::pow(n, 2)+n))>>1;
}




// 对全局静态变量初始化
int Solution64::n = 0;
int Solution64::sum = 0;

Solution64::Solution64() {
    // 没调用一次对n加1
    ++n;

    // 没调用一次对sum加n
    sum += n;
}

void Solution64::reset() {
    n=0;
    sum=0;
}

int Solution64::getSum() {
    return sum;
}

int Solution64::sumNums3(int n) {
    Solution64::reset();

    // 创建n个类对象，
    // 构造函数调用n次
    auto* s = new Solution64[n];

    // 释放n个对象的空间
    delete []s;
    // 将对象指针设为null
    s = nullptr;

    return getSum();
}



int Solution64::sumNums4(int n) {
    // 函数指针数组
    static fun f[2] = {terminator, sumNums4};

    // 1. n > 0时，f[!!n] = f[1] = sunNums3,
    // 此时计算: n+(n-1)+(n-2)+...+1
    // 2. n = 0时，f[!!n] = f[0] = terminator
    // 此时返回0，计算终止
    return n + f[!!n](n-1);
}

int Solution64::terminator(int n) {
    return 0;
}





