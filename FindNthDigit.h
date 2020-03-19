//
// Created by Wanhui on 3/19/20.
//

#ifndef SWORDTOOFFER_FINDNTHDIGIT_H
#define SWORDTOOFFER_FINDNTHDIGIT_H

/*
 * 剑指offer 44 数字序列中某一位的数字
 *
 * 数字以0123456789101112131415…的格式序列化到一个字符序列中。
 * 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
 * 请写一个函数，求任意第n位对应的数字。
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：3
 *
 * 示例 2：
 *
 * 输入：n = 11
 * 输出：0
 *
 * 限制：
 * 0 <= n < 2^31
 * */


class Solution44 {
public:
    /*
     * 数学规律
     *
     * 通过观察有以下规律：
     * 123456789             9个数     9*1位数字
     * 10 11 12 ... 98 99    90个数    90*2位数字
     * 100 101 ... 998 999   900个数   900*3位数字
     * ......
     *
     * 对于第n位对应的数字，定义该数字对应的数为number，以下三步计算：
     * 1. 找到该数字对应的数的位数digits;
     * 2. 确定对应的数的数值为number；
     * 3. 确定返回值是number的哪一位数字idx。
     *
     * 例如：n = 365
     * 1. 通过计算知n的位数为：digits = 3，而计算后n = 365 - 9 + 90 * 2 = 176，
     *    表示number是三位数中的第176个数
     * 2. 由1知number是三位数中的第176个数，计算后number = 10^2 + 176/3 = 158
     * 3. idx是所求数字在number中的位数，当idx == 0时，表示该数字是number-1的最后一位数字。
     *    通过计算知idx = n % digits = 176 % 3 = 2，说明所求数字是number = 158的第2位数字5。
     * */
    int findNthDigit(int n);
};


#endif //SWORDTOOFFER_FINDNTHDIGIT_H
