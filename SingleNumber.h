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
    /*
     * 哈希表 O(n) O(n)
     *
     * 将数组中的数和其对应出现的次数存储到哈希表中，遍历哈希表，返回次数为1的数。
     * */
    int singleNumber(std::vector<int> &nums);

    /*
     * 位运算 O(n) O(1)
     *
     * 如果一个数字出现三次，则它二进制表示的每一位也出现三次。
     * 如果把所有出现三次的数字的二进制表示的每一位都分别加起来，则每一位的和都能被3整除。
     * 将数组中的所有数字的二进制表示的每一位都加起来。如果某一位的和能被3整除，
     * 则只出现一次数字的二进制表示中对应的那一位是0，否则就是1。
     * */
    int singleNumber2(std::vector<int> &nums);
};


#endif //SWORDTOOFFER_SINGLENUMBER_H
