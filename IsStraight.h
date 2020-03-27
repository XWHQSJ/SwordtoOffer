//
// Created by Wanhui on 3/27/20.
//

#ifndef SWORDTOOFFER_ISSTRAIGHT_H
#define SWORDTOOFFER_ISSTRAIGHT_H

/*
 * 剑指offer 61 扑克牌中的顺子
 *
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
 * 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。
 * A 不能视为 14。
 *
 * 示例 1:
 *
 * 输入: [1,2,3,4,5]
 * 输出: True
 *
 * 示例 2:
 *
 * 输入: [0,0,1,2,5]
 * 输出: True
 *
 * 限制：
 * 数组长度为 5
 * 数组的数取值为 [0, 13] .
 * */


#include <vector>

class Solution61 {
public:
    /*
     * 首先对数组进行排序，再计数数组中0的个数。因为0可以代表任何数，所以0可以填充顺子中缺少的数。
     * 如果数组为顺子，则数组中0的个数必然大于或等于数组中缺少的数。
     * 如果等于，则0直接填充即可；如果大于，表示0可以填充最后面的数。
     * 所以只需要计算排序好后的数组中缺少数的个数，在与0的个数比较即的结果。
     * */
    bool isStraight(std::vector<int> &nums);
};


#endif //SWORDTOOFFER_ISSTRAIGHT_H
