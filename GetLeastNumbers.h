//
// Created by Wanhui on 2/28/20.
//

#ifndef SWORDTOOFFER_GETLEASTNUMBERS_H
#define SWORDTOOFFER_GETLEASTNUMBERS_H

/*
 * 剑指offer 40 最小的k个数
 *
 * 输入整数数组 arr ，找出其中最小的 k 个数。
 * 例如，输入4、5、1、6、2、7、3、8这8个数字，
 * 则最小的4个数字是1、2、3、4。
 *
 * 示例 1：
 *
 * 输入：arr = [3,2,1], k = 2
 * 输出：[1,2] 或者 [2,1]
 *
 * 示例 2：
 * 输入：arr = [0,1,2,1], k = 1
 * 输出：[0]
 *
 * 限制：
 * 0 <= k <= arr.length <= 10000
 * 0 <= arr[i] <= 10000
 * */


#include <vector>

class Solution40 {
public:
    /*
     * 方法一 排序法
     *
     * 将数组按照从小到大排序，
     * 从有序数组中取前k个数返回
     * */
    std::vector<int> getLeastNumbers(std::vector<int> &arr, int k);

    /*
     * 方法二 大顶堆
     *
     * 使用大顶堆排序,大顶堆构建需要O(n)，
     * 但查找只需要O(logn)
     * */
    std::vector<int> getLeastNumbers2(std::vector<int> &arr, int k);
};


#endif //SWORDTOOFFER_GETLEASTNUMBERS_H
