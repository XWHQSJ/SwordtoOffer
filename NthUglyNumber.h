//
// Created by Wanhui on 2/15/20.
//

#ifndef SWORDTOOFFER_NTHUGLYNUMBER_H
#define SWORDTOOFFER_NTHUGLYNUMBER_H

/*
 * 剑指offer 49 丑数
 * 我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
 *
 * 示例:
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 *
 * 说明:
 * 1 是丑数。
 * n 不超过1690。
 * */

class Solution49 {
public:
    /*
     * 方法 动态规划（Dynamic Program）
     * 丑数的生成公式是：uglyNum = 2^x * 3^y * 5^z
     * 即x=y=z=0时，uglyNum = 1，
     * x = y = z = 1时，生成2,3,5等
     * 生成过程是先生成小的数，
     * 再在小的数的基础上生成后面的数。
     * 使用三个指针p2,p3,p5所对应的数值表示丑数，
     * 即每次都为vec[i] = min(vec[p2]*2, vec[p3]*3, vec[p5]*5)
     * 如果vec[i]==vec[p2/3/5]*2/3/5，对应的将p2/3/5加一
     * 第n个数即vec[n-1]
     * */
    int nthUglyNumber(int n);
};


#endif //SWORDTOOFFER_NTHUGLYNUMBER_H
