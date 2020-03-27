//
// Created by Wanhui on 3/27/20.
//

#ifndef SWORDTOOFFER_CONSTRUCTARR_H
#define SWORDTOOFFER_CONSTRUCTARR_H

/*
 * 剑指offer 66 构造乘积数组
 *
 * 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
 * 其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
 * 不能使用除法。
 *
 * 示例:
 *
 * 输入: [1,2,3,4,5]
 * 输出: [120,60,40,30,24]
 *
 * 提示：
 * 所有元素乘积之和不会溢出 32 位整数
 * a.length <= 100000
 * */


#include <vector>

class Solution66 {
public:
    /*
     * 对称法
     *
     * 结果B[i] = A[0]*A[1]...A[i-1]*A[i+1]...A[n-1]可以看做
     * C[i] = A[0]*A[1]...A[i-1]和D[i] = A[i+1]*A[i+2]...A[n-2]*A[n-1]两部分乘积。
     * 所以C[i]可以自上而下顺序计算：
     *      C[i] = C[i-1]*A[i-1]
     * D[i]可以自下而上顺序计算：
     *      D[i] = D[i+1]*A[i+1]
     *
     * 大致的意思是：先计算该数左边所有数的乘积，存到该数；
     *               再计算该数右边所有数的乘积，存到临时数，
     *               最后将临时数乘该数，存到该数。
     * */
    std::vector<int> constructArr(std::vector<int>& a);
};


#endif //SWORDTOOFFER_CONSTRUCTARR_H
