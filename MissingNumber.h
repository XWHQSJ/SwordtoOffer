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
     * 因为n-1个数有序且不重复，则在缺失的数对应的索引前，每个数的大小与自身索引相等，
     * 缺失数对应的索引后，每个数的大小都比索引大1。
     * 可以使用二分查找中间数：
     * 1. 如果中间数的大小与对应索引不相等，则：
     *    1> 如果中间数前一个数的大小与索引相等，则该中间数的索引为缺失数；
     *    2> 如果中间数前一个数的大小与索引不相等，则表示缺失数的索引在左边，继续对左边进行二分查找。
     * 2. 如果中间数的大小与对应索引相等，则表示缺失数的索引在数组右边，急速对右边进行二分查找。
     * */
    int missingNumber2(std::vector<int> &nums);

    /*
     * 数学规律
     *
     * 先使用公式计算 sum1 = (n * (n-1))/2，即n个数的和，再计算数组中所有数的和sum2，
     * 最后num = sum1 - sum2。
     * */
    int missingNumber3(std::vector<int> &nums);
};


#endif //SWORDTOOFFER_MISSINGNUMBER_H
