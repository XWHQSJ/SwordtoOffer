//
// Created by Wanhui on 2/16/20.
//

#ifndef SWORDTOOFFER_NUMWAYS_H
#define SWORDTOOFFER_NUMWAYS_H

/*
 * 剑指offer 10-2 青蛙跳台阶问题
 *
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
 * 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 *
 * 示例 2：
 *
 * 输入：n = 7
 * 输出：21
 *
 * 提示：
 * 0 <= n <= 100
 * */


// 本题与斐波那契数列思路相同
class Solution10_2 {
public:

    /*
     * 方法1 递归法 超时
     * 由于递归栈过多的原因，太耗时
     * */
    int numWays(int n);

    /*
     * 方法2 非递归法
     * 使用数组存储计算的数，
     * 最后取第n个数即可
     * */
    int numWays2(int n);
};


#endif //SWORDTOOFFER_NUMWAYS_H
