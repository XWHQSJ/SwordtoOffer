//
// Created by Wanhui on 3/23/20.
//

#ifndef SWORDTOOFFER_TWOSUM60_H
#define SWORDTOOFFER_TWOSUM60_H

/*
 * 剑指offer 60 n个骰子的点数
 *
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。
 * 输入n，打印出s的所有可能的值出现的概率。
 * 你需要用一个浮点数数组返回答案，
 * 其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
 *
 * 示例 1:
 *
 * 输入: 1
 * 输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
 *
 * 示例 2:
 *
 * 输入: 2
 * 输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 *
 * 限制：
 * 1 <= n <= 11
 * */


#include <vector>

class Solution60 {
public:
    /*
     * 动态规划
     *
     * 动态规划解决问题的三个步骤：
     * 1. 表示状态；
     * 2. 状态转移方程；
     * 3. 边界处理
     *
     * 1. 表示状态
     * 一共投掷n枚骰子，要求当投掷完n枚骰子后，各个点数出现的次数。
     * 定义状态数组dp[i][j]，表示投掷完i枚骰子后，点数j出现的次数。
     * 该状态数组第一维表示投掷完了几枚骰子，第二维表示投掷完骰子后，可能出现的点数。
     *
     * 2. 状态转移方程
     * 第n枚骰子，投掷完可能的点数为1,2,3,4,5,6，因此投掷完n枚骰子后点数j出现的次数，
     * 由投掷完n-1枚骰子，再加上第n枚投掷完出现的点数确定：
     * dp[n][j] = dp[n-1][j-1] + dp[n-1][j-2] + dp[n-1][j-3] + dp[n-1][j-4] + dp[n-1][j-5] + dp[n-1][j-6]
     *
     * 3. 边界处理
     * 初始化初始状态的值，即投掷完1枚骰子后，他的可能点数为1,2,3,4,5,6，每个点数出现的次数为1：
     * dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1
     * */
    std::vector<double> twoSum(int n);

    // 空间优化
    // 每个阶段的状态都只和它迁移阶段的状态有关，因此可以使用一维数组保存状态。
    // 用一维数组保存一个阶段的状态，在对下一阶段可能出现的点数j从大到小遍历，
    // 实现一个阶段到下一个阶段的状态转移。
    std::vector<double> twoSum2(int n);
};


#endif //SWORDTOOFFER_TWOSUM60_H
