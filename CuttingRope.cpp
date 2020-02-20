//
// Created by Wanhui on 2/20/20.
//

#include <cmath>
#include <vector>
#include "CuttingRope.h"

int Solution14_1::cuttingRope(int n) {
    // 当n小于4时返回n-1
    if (n <= 3) {
        return n - 1;
    }

    // 计算整数部分和余数部分
    int a = n / 3, b = n % 3;

    // 如果余数为0，则正好为3的整数倍
    if (b == 0) {
        return pow(3, a);
    }

    // 如果余数为1，则3+1可以合并为4
    if (b == 1) {
        return pow(3, a - 1) * 4;
    }

    // 如果余数为2，则直接计算
    return pow(3, a) * 2;
}

int Solution14_1::cuttingRope2(int n) {
    // 当n小于4时返回n-1
    if (n <= 3) {
        return n - 1;
    }

    // 记忆数组
    // 存储上一轮的最优结果
    std::vector<int> dp(n + 1, 0);
    //初始化为1
    dp[1]=1;

    int i, j;
    for (i = 4; i <= n; i++) {
        // i为界限减少重复计算，
        // 因为 j*(i-j) == (i-j)*j
        for (j = 1; j < i; j++) {
            // dp[i]为上一轮最优结果
            // 里面实际上是比较: dp[i-j]*j 和 (i-j)*j 的大小
            // 即比较 dp[i-j] 和 i-j 的大小
            dp[i] = std::max(dp[i], std::max(dp[i-j],i-j)*j);
        }
    }

    return dp[n];
}
