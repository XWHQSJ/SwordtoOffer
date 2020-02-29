//
// Created by Wanhui on 2/29/20.
//

#ifndef SWORDTOOFFER_MAXSUBARRAY_H
#define SWORDTOOFFER_MAXSUBARRAY_H

/*
 * 剑指offer 42 连续子数组的最大和
 *
 * 输入一个整型数组，数组里有正数也有负数。
 * 数组中的一个或连续多个整数组成一个子数组。
 * 求所有子数组的和的最大值。要求时间复杂度为O(n)。
 *
 * 示例1:
 *
 * 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 *
 * 提示：
 * 1 <= arr.length <= 10^5
 * -100 <= arr[i] <= 100
 *
 * 进阶:
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * */


#include <vector>

class Solution42 {
public:
    /*
     * 方法一 贪心法 O(n)
     *
     * 当叠加的和小于0时，就从下一个数重新开始，
     * 同时更新最大和的值(最大值可能为其中某个值)，
     * 当叠加和大于0时，将下一个数值加入和中，
     * 同时更新最大和的值，依此继续。
     *
     * 举例： nums = [-2,1,-3,4,-1,2,1,-5,4]
     * sum = INT_MIN <= 0-> sum = -2 <= 0 -> sum = 1 > 0 ->
     * -> sum = -2 <= 0 -> sum = 4 > 0 -> sum = 3 > 0 ->
     * -> sum = 5 > 0 -> sum = 6 > 0 -> sum = 1 > 0 ->
     * -> sum = 5 > 0
     * res = [-2, 1, 1, 4, 4, 5, 6, 6, 6]
     * 最终返回 res = 6
     * */
    int maxSubArray(std::vector<int> &nums);

    /*
     * 方法二 分治法 O(nlogn)
     *
     * 分治法模板：
     * 1. 定义基本情况
     * 2. 将问题分解为子问题并递归解决子问题
     * 3. 合并子问题的解以获得原始问题的解
     *
     * 将nums由中点mid分为三种情况：
     * 1. 最大子串在左边
     * 2. 最大子串在右边
     * 3. 最大子串跨中点，左右都有
     *
     * 当子串在左边或右边时，继续分中点递归分解到一个数为止，
     * 对于递归后横跨的子串，再分治为左侧和右侧求最大子串，
     * 可使用贪心算法求最大子串值，再合并为原始的最大子串值
     *
     * 图 连续子数组的最大和.png
     * */
    int maxSubArray2(std::vector<int> &nums);

    int helper(std::vector<int> &nums, int left, int right);

    int crossSum(std::vector<int> &nums, int left, int right, int mid);

    /*
     * 方法三 动态规划—— Kadane算法 O(n)
     *
     * 在整个数组或子在固定大小的滑动窗口中找到总和或最大值或最小值的问题，
     * 可通过动态规划(DP)在线性时间内解决
     *
     * 两种标志DP适用于数组：
     * 1. 常数空间，沿数组移动并子啊原数组修改；
     * 2. 线性空间，首先沿left->right方向移动，然后沿right->left方向移动，最后合并结果。
     *
     * 本题可通过修改数组跟踪当前位置的最大和，
     * 在知道当前位置的最大和后更新全局最大和。
     * */
    int maxSubArray3(std::vector<int> &nums);
};


#endif //SWORDTOOFFER_MAXSUBARRAY_H
