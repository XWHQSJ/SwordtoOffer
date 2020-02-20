//
// Created by Wanhui on 2/19/20.
//

#ifndef SWORDTOOFFER_PRINTNUMBERS_H
#define SWORDTOOFFER_PRINTNUMBERS_H

/*
 * 剑指offer 17 打印从1到最大的n位数
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
 * 比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 *
 * 示例 1:
 *
 * 输入: n = 1
 * 输出: [1,2,3,4,5,6,7,8,9]
 *
 * 说明：
 * 用返回一个整数列表来代替打印
 * n 为正整数
 * */


#include <vector>

typedef long long int LL;

class Solution17 {
public:
    /*
     * 方法1　函数库方法
     * 直接使用cmath函数库中的pow(x,n)函数
     * 即x^n=pow(x,n)；
     *
     * 也可类似于进制转换，
     * 直接使用手动乘法
     * */
    std::vector<int> printNumbers(int n);

    /*
     * 方法2　快速幂方法
     * 求x=base^a，base是底数，a为指数幂
     * 对base^a进行分治，即：
     *
     * -- base^a = base^(a/2+a/2) = base^(a/2) * base^(a/2)                     a mode 2 = 0;
     * -- base^a = base^((a-1)/2+(a-1)/2) = base^((a-1)/2) * base^((a-1)/2)     a mode 2 = 1;
     *
     * 如此就能够通过将a分解成二进制，
     * 对其使用与&和右移>>操作了
     * */
    std::vector<LL> printNumbers2(LL base, LL a);


    /*
     * 通用方法1：模指数运算－分治原理
     * 分治法：分、治再归并
     * 求x = a^e mod m，a是底数，e为指数幂，m是模数
     *
     * -- a^e mod m = a^(e1+e2) mod m = (a^e1 mod m) * (a^e2 mod m) mod m     e = e1+e2
     *
     * 分别计算出分治的a^e1 mod m 和a^e2 mod m 结果
     * 再将它们合并为a^e mod m
     *
     *
     * 通用方法2：模指数运算－二进制算法
     * 以二进制方式分拆指数
     * 将e表示为二进制dn-1 dn-2 ... d1 d0，此处di=0或１
     * e = dn-1*2^(n-1) + ... + d1*2 + d0 = Dn-1 + ... D1 + D0 (Di = di*2^i)
     * 所以a^e = a^(Dn-1) * a^(Dn-2) * ... * a^D1 * a^D0 (a^Di)
     * 分治计算：Ai = a^Di mod m, i = 0, 1, ..., n-1
     * a^(2^(i+1)) mod m = (a^(2^i) mod m) * (a^(2^i) mod m) mod m
     * 计算O(loge)次
     * 实用于通用函数
     * */
    std::vector<LL> printNumbersTemplate(LL base, LL a, LL m);
};


#endif //SWORDTOOFFER_PRINTNUMBERS_H
