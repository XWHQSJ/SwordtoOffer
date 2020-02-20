//
// Created by Wanhui on 2/20/20.
//

#include "CuttingRopeII.h"

int Solution14_2::cuttingRope(int n) {
    // 小于3的数直接返回n-1
    if(n<=3){
        return n-1;
    }

    int res = 1;
    // 当n=4时，其拆分乘积最大为4
    // 保证余数大于0
    // 所以余数由0,1,2变为2,3,4
    while (n>4){
        // n = 3a+b
        // 所以不断剪3，到余数n=b
        n-=3;

        // res = 3^a*b
        // 此处res只乘n/3的整数部分
        res *= 3;
        res = res % 1000000007;
    }

    // 余数n=b
    // 当b=2 res=3^a*b
    // 当b=3 res=3^(a-1)*b
    // 当b=4 res=3^(a-1)*b
    res *= n;

    return  res % 1000000007;
}
