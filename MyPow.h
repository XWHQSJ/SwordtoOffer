//
// Created by Wanhui on 2/20/20.
//

#ifndef SWORDTOOFFER_MYPOW_H
#define SWORDTOOFFER_MYPOW_H

/*
 * 剑指offer 16 数值的整数次方
 *
 * 实现函数double Power(double base, int exponent)，
 * 求base的exponent次方。
 * 不得使用库函数，同时不需要考虑大数问题。
 *
 * 示例 1:
 *
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 *
 * 示例 2:
 *
 * 输入: 2.10000, 3
 * 输出: 9.26100
 *
 * 示例 3:
 *
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2-2 = 1/22 = 1/4 = 0.25
 *
 * 说明:
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
 * */


class Solution16 {
public:
    /*
     * 快速幂方法
     * 求x=base^a，base是底数，a为指数幂
     * 对base^a进行分治，即：
     *
     * -- base^a = base^(a/2+a/2) = base^(a/2) * base^(a/2)                     a mode 2 = 0;
     * -- base^a = base^((a-1)/2+(a-1)/2) = base^((a-1)/2) * base^((a-1)/2)     a mode 2 = 1;
     *
     * 如此就能够通过将a分解成二进制，
     * 对其使用与&和右移>>操作了
     *
     * 其它 ： 库函数法和手写幂函数法,
     * 注意 ： INT_MIN 的绝对值因为比 INT_MAX 大1，无法进行直接取反操作
     * 可以先移位后再取反，也可以强制转换为 unsigned int类型再取反
     * */
    double myPow(double x, int n);
};


#endif //SWORDTOOFFER_MYPOW_H
