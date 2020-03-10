//
// Created by Wanhui on 3/10/20.
//

#ifndef SWORDTOOFFER_SUMNUMS_H
#define SWORDTOOFFER_SUMNUMS_H

/*
 * 剑指offer 64 求1+2+...+n
 *
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等
 * 关键字及条件判断语句（A?B:C）。
 *
 * 示例 1：
 *
 * 输入: n = 3
 * 输出: 6
 *
 * 示例 2：
 *
 * 输入: n = 9
 * 输出: 45
 *
 * 限制：
 * 1 <= n <= 10000
 * */



typedef int (*fun)(int);

class Solution64 {
public:
    /*
     * 方法1 && 短路法
     *
     * && 的短路特性是——
     * A && B :
     * 当A为true时，返回表达式B的bool值；
     * 当A为false，返回false。
     * */
    int sumNums(int n);


    /*
     * 方法2 公式法
     *
     * 计算公式：
     * 1+2+...+(n-1)+n = ((n+1)n)/2 = (pow(n,2)+n)>>1
     *
     * 此处使用右移代替除法，使用求幂函数代替乘法。
     * */
    int sumNums2(int n);


    /*
     * 方法3 构造函数法
     *
     * 创建一个类的n个实例，该类的构造函数将会被调用n次，
     * 在构造函数中对全局静态变量n和sum进行累加
     * */
    int sumNums3(int n);

    // 累加n和sum的构造函数
    Solution64();
    // 置0静态函数
    static void reset();
    // 获取全局静态变量sum值的静态函数
    static int getSum();

private:
    static int n;
    static int sum;


public:
    /*
     * 方法4 函数指针法
     *
     * 使用函数返回0作为终止条件，
     * 定义函数指针，该函数指针数组指向函数terminator和sumNums3，
     * 当f[!!n]中的(!!n)为0时指向terminator，为1时指向sumNums3。
     *
     * 1. 当n>0时,(!!n)为1，此时sumNums3函数递归计算：n+(n-1)+(n-2)+...+1；
     * 2. 当n=0时,(!!n)为0，此时terminator函数返回0，运算结束。
     *
     * 此处f[!!n]这样使用的原因是，函数指针数组包含两个函数指针，
     * 而要判断n为0时指向terminator，即f[0]，所以将其中的n转化为bool值(!!n)。
     * */
    static int sumNums4(int n);

    // 终止函数
    static int terminator(int n);
};

/*
 * 方法4 模板类型法
 *
 * 使用模板类型的方法，递归计算：N = n+(n-1)+...+1
 * 当递归到参数为1的类型时，递归结束。
 *
 * 由于此过程是在编译过程中完成的，因此需要n为确定的常量。
 * */
template <int n> struct sumNums5{
    enum VALUE{N=sumNums5<n-1>::N+n};
};

// 终止类型
template <> struct sumNums5<1>{
    enum VALUE{N=1};
};


#endif //SWORDTOOFFER_SUMNUMS_H
