//
// Created by Wanhui on 3/13/20.
//

#ifndef SWORDTOOFFER_TRANSLATENUM_H
#define SWORDTOOFFER_TRANSLATENUM_H

/*
 * 剑指offer 46 把数字翻译成字符串
 *
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
 * 1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，
 * 用来计算一个数字有多少种不同的翻译方法。
 *
 * 示例 1:
 *
 * 输入: 12258
 * 输出: 5
 * 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 *
 * 提示：
 * 0 <= num < 231
 * */


class Solution46 {
public:
    /*
     * 方法1 动态规划
     *
     * 整数翻译的字符串的种数因为有两种翻译方式，
     * 类似于青蛙跳台阶，后一种状态值由前两种状态值决定。
     * 这是一种递归的思想，考虑到重复性，可以归结为动态规划。
     *
     * 动态规划的状态转移方程为： dp[i] =
     *     1. dp[i-1]            当num[i]和num[i-1]不能翻译为一个字符时
     *     2. dp[i-1]+dp[i-2]    当num[i-1]和num[i-2]能翻译为一个字符时
     *
     * 根据状态方程，需要先初始化初始状态值dp[1]和dp[2]，
     * 之后再根据方程公式进行判断即可。
     * */
    int translateNum(int num);
};


#endif //SWORDTOOFFER_TRANSLATENUM_H
