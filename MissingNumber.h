//
// Created by Wanhui on 3/21/20.
//

#ifndef SWORDTOOFFER_MISSINGNUMBER_H
#define SWORDTOOFFER_MISSINGNUMBER_H

/*
 * 剑指offer 53-II 0-n-1中缺失的数字
 *
 * 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
 * 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
 *
 * 示例 1:
 *
 * 输入: [0,1,3]
 * 输出: 2
 *
 * 示例 2:
 *
 * 输入: [0,1,2,3,4,5,6,7,9]
 * 输出: 8
 *
 * 限制：
 * 1 <= 数组长度 <= 1000
 * */


#include <vector>

class Solution53_2 {
public:
    /*
     * 桶排序 O(n) O(n)
     *
     * 因为n-1个数是有序且不重复的，所以可以将n个数按照它们的大小存储在桶数组中，
     * 桶数组中存放它们出现的次数，如果该次数为0，表示该数是缺失的。
     * */
    int missingNumber(std::vector<int> &nums);

    /*
     * 二分查找 O(logn) O(1)
     *
     *
     * */
    int missingNumber2(std::vector<int> &nums);
};


#endif //SWORDTOOFFER_MISSINGNUMBER_H
