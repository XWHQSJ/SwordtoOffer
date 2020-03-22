//
// Created by Wanhui on 3/22/20.
//

#ifndef SWORDTOOFFER_REVERSEPAIRS_H
#define SWORDTOOFFER_REVERSEPAIRS_H

/*
 * 剑指offer 51 数组中的逆序对
 *
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组，求出这个数组中的逆序对的总数。
 *
 * 示例 1:
 *
 * 输入: [7,5,6,4]
 * 输出: 5
 *
 * 限制：
 * 0 <= 数组长度 <= 50000
 * */


#include <vector>

class Solution51 {
public:
    int reversePairs(std::vector<int>& nums);
};


#endif //SWORDTOOFFER_REVERSEPAIRS_H
