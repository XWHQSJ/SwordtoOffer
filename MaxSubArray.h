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
     * 方法一 规律法
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
    int maxSubArray(std::vector<int>& nums);

    /*
     * 方法二 动态规划
     *
     *
     *
     * */
    int maxSubArray2(std::vector<int>& nums);
};


#endif //SWORDTOOFFER_MAXSUBARRAY_H
