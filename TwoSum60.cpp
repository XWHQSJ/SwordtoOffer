//
// Created by Wanhui on 3/23/20.
//

#include <cmath>
#include "TwoSum60.h"

std::vector<double> Solution60::twoSum(int n) {
    if (n < 0) {
        return {};
    }

    // 定义状态数组
    std::vector<std::vector<int>> dp(12, std::vector<int>(67, 0));

    // 初始化第1枚骰子投掷完后每个点数出现的次数
    for (int i = 1; i <= 6; i++) {
        dp[1][i] = 1;
    }

    // 从第2枚骰子开始，计算n枚骰子投掷完后，
    // 每个点数出现的次数
    for (int i = 2; i <= n; i++) {
        // j = i是因为，j的次数肯定不会小于投掷的骰子的数目
        // 骰子的最小点数为1，所以每枚骰子最少1点
        for (int j = i; j <= 6 * i; j++) {
            // 相较于上一枚骰子
            for (int k = 1; k <= 6; k++) {
                if (j - k <= 0) {
                    break;
                }
                // 状态转移方程
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    // 计算n枚骰子的总点数
    int total = std::pow(6, n);
    std::vector<double> ans;

    // 计算n枚骰子投掷完后，点数和出现的概率
    for (int i = n; i <= 6 * n; i++) {
        ans.push_back(dp[n][i] * 1.0 / total);
    }

    return ans;
}

std::vector<double> Solution60::twoSum2(int n) {
    if (n < 0) {
        return {};
    }

    // 保存状态的一维数组
    std::vector<double> dp(n * 6 + 1, 0.0);
    // 对一维数组初始化
    for (int i = 1; i <= 6; i++) {
        dp[i] = 1.0 / 6.0;
    }

    // 从第2枚骰子开始计算点数和s出现的概率
    for (int i = 2; i <= n; i++) {
        for (int j = i * 6; j >= i; j--) {
            // 每次更新dp[j]的值为0
            dp[j] = 0;
            // k = j - 1，，并且k--
            // 实现j-1,j-2,...,j-6
            // 同时要保证j是要大于等于i的，所以
            // k = j - 1 >= i - 1
            for (int k = j - 1; k >= i - 1 && k >= j - 6; k--) {
                // 计算点数和出现的概率
                dp[j] += dp[k] * 1.0 / 6.0;
            }
        }
    }

    std::vector<double> ans(dp.begin() + n, dp.end());

    return ans;
}
