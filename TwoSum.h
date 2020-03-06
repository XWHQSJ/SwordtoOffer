//
// Created by Wanhui on 3/6/20.
//

#ifndef SWORDTOOFFER_TWOSUM_H
#define SWORDTOOFFER_TWOSUM_H

/*
 * 剑指offer 57 和为s的两个数字
 *
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
 * 如果有多对数字的和等于s，则输出任意一对即可。
 *
 * 示例 1：
 *
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[2,7] 或者 [7,2]
 *
 * 示例 2：
 *
 * 输入：nums = [10,26,30,31,47,60], target = 40
 * 输出：[10,30] 或者 [30,10]
 *
 * 限制：
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * */


#include <vector>

class Solution57 {
public:
    /*
     * 方法1 双侧指针
     *
     * 因为是求两个数的和等于target，那么在小于target的数中找，
     * 又因为数组是递增有序的，所以可以设置双侧指针，
     * 指针i指向最左侧，指针j指向数组右侧第一个不大于target的数，
     * 当指针i,j指向的数的和大于target，表示右侧j指向的数太大，
     * 需要减小j指向的数，所以将右侧指针向左移动，
     * 当指针i,j指向的数的和小于target，表示左侧i指向的数太小，
     * 需要增大i指向的数，所以将左侧指针向右移动。
     * */
    std::vector<int> twoSum(std::vector<int> &nums, int target);


    /*
     * 方法2 哈希表法
     *
     * 根据key: target-nums[i] 和 value: nums[i]，
     * 构建数组每个数与它们对应差的哈希表，
     * 当使用差nums[j]在哈希表中寻找对应值时，
     * 如果找到，即代表nums[j] = target - nums[i].
     * */
    std::vector<int> twoSum2(std::vector<int> &nums, int target);
};


#endif //SWORDTOOFFER_TWOSUM_H
