//
// Created by Wanhui on 3/22/20.
//

#ifndef SWORDTOOFFER_SINGLENUMBER_H
#define SWORDTOOFFER_SINGLENUMBER_H

/*
 * 剑指offer 56-II 数组中数字出现的次数II
 *
 * 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
 *
 * 示例 1：
 *
 * 输入：nums = [3,4,3,3]
 * 输出：4
 *
 * 示例 2：
 *
 * 输入：nums = [9,1,7,9,7,9,7]
 * 输出：1
 *
 * 限制：
 * 1 <= nums.length <= 10000
 * 1 <= nums[i] < 2^31
 * */


#include <vector>

class Solution56_2 {
public:
    int singleNumber(std::vector<int>& nums);
};


#endif //SWORDTOOFFER_SINGLENUMBER_H
