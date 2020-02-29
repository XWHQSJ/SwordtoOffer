//
// Created by Wanhui on 2/16/20.
//

#ifndef SWORDTOOFFER_FIBONACCI_H
#define SWORDTOOFFER_FIBONACCI_H

/*
 * 剑指offer 10-1 斐波那契数列
 *
 * 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 *
 * 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：1
 *
 * 示例 2：
 *
 * 输入：n = 5
 * 输出：5
 *
 * 提示：
 * 0 <= n <= 100
 * */


class Solution10_1 {
public:

    /*
     * 方法1 递归法 超时
     *
     * 直接使用公式递归即可，但当递归层数较多时，
     * 一是递归栈内存开销大，
     * 二是递归操作的时间消耗非常大。
     * */
    int fibonacci(int n);

    /*
     * 方法2 非递归法
     *
     * 空间换时间，使用一个数组存储计算出的斐波那契数，
     * 再返回第n个数即可。
     * */
    int fibonacci2(int n);
};


#endif //SWORDTOOFFER_FIBONACCI_H
