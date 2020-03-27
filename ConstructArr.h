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
    std::vector<int> constructArr(std::vector<int>& a);
};


#endif //SWORDTOOFFER_CONSTRUCTARR_H
