//
// Created by Wanhui on 3/18/20.
//

#ifndef SWORDTOOFFER_COUNTDIGITONE_H
#define SWORDTOOFFER_COUNTDIGITONE_H

/*
 * 剑指offer 43 1-n整数中1出现的次数
 *
 * 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
 * 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
 *
 * 示例 1：
 *
 * 输入：n = 12
 * 输出：5
 *
 * 示例 2：
 *
 * 输入：n = 13
 * 输出：6
 *
 * 限制：
 * 1 <= n < 2^31
 * */


class Solution43 {
public:
    /*
     * 数学规律 O(log<10>n)
     *
     * 每10个数，个位的1就会出现一次，每100个数，十位的1就会出现一次。
     * 依此递推公式 (n/(i*10))*i
     *
     * 同时，如果十位上的数是1，则最后1的数量要加上 x+1，其中x是个位上的数值。
     * 如果十位上的数大于1，则十位上为1的所有的数都符合要求，次数最后1的数量要加10。
     * 依此递推公式 std::min(std::max((n mod (i*10)) - i + 1, 0), i)
     *
     * 所以最后1的总数公式是：
     * (n / (i * 10)) * i + std::min(std::max((n mod (i * 10)) - i + 1, 0), i)
     * */
    int countDigitOne(int n);
};


#endif //SWORDTOOFFER_COUNTDIGITONE_H
