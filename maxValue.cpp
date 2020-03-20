//
// Created by Wanhui on 3/20/20.
//

#include "maxValue.h"

int Solution47::maxValue(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }

    // 矩阵的行数和列数
    int m = grid.size();
    int n = grid[0].size();

    // 存储当前礼物最大值的矩阵，
    // 对应礼物矩阵的每个点
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    // 对礼物最大值矩阵的第一行和第一列初始化
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // 当前点的礼物最大值是当前礼物的值加上左点或上点礼物最大值中较大的值
    // 状态转移方程:
    // dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // 返回礼物最大值矩阵的最后一个点的值
    return dp[m - 1][n - 1];
}

int Solution47::maxValue2(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }

    // 矩阵的行数和列数
    int m = grid.size();
    int n = grid[0].size();

    // 存储当前礼物的最大值
    std::vector<int> dp(n + 1, 0);

    // dp[j+1]保存上一点的最大值
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[j + 1] = std::max(dp[j], dp[j + 1]) + grid[i][j];
        }
    }

    return dp[n];

//    // 初始化第一行的礼物最大值
//    for (int j = 0; j < n; j++) {
//        dp[j] = dp[j - 1] + grid[0][j];
//    }
//
//    for (int i = 1; i < m; i++) {
//        // 初始化第一列的礼物最大值
//        dp[0] += grid[i][0];
//
//        // 因为dp[j]在更新前仍然是上面点的礼物最大值，
//        // 所以可以利用此压缩空间
//        for (int j = 1; j < n; j++) {
//            dp[j] = std::max(dp[j], dp[j - 1]) + grid[i][j];
//        }
//    }
//
//    return dp[n - 1];
}
