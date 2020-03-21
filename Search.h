//
// Created by Wanhui on 3/21/20.
//

#ifndef SWORDTOOFFER_SEARCH_H
#define SWORDTOOFFER_SEARCH_H

/*
 * 剑指offer 53-I 在排序数组中查找数字I
 *
 * 统计一个数字在排序数组中出现的次数。
 *
 * 示例 1:
 *
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: 2
 *
 * 示例 2:
 *
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: 0
 *
 * 限制：
 * 0 <= 数组长度 <= 50000
 * */



#include <vector>

class Solution53_1 {
public:
    /*
     * 哈希表 O(1) O(n)
     *
     * 使用std::unordered_map哈希表存储数组中每个数字和对应出现的次数，
     * 再在哈希表中查找target是否存在，如果存在返回出现的次数，不存在返回0。
     * */
    int search(std::vector<int> &nums, int target);


    /*
     * 二分查找 O(logn) O(1)
     *
     * 普通的二分查找能够在最优情况下的查询效率达到O(logn)，但如果target在数组中出现次数很多，
     * 则普通的二分查找的效率会到达最坏情况O(n)。所以需要更改二分查找的策略。
     * 普通的二分查找是先在数组中找到对应的target，再遍历O(k)时间找到所有target。
     * 因为数组是有序的，可以通过找到第一个target的索引和最后一个target的索引，
     * 则target对应的个数就是: lastT - firstT + 1 。
     * */
    int search2(std::vector<int> &nums, int target);
};


#endif //SWORDTOOFFER_SEARCH_H
