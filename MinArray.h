//
// Created by Wanhui on 2/16/20.
//

#ifndef SWORDTOOFFER_MINARRAY_H
#define SWORDTOOFFER_MINARRAY_H

/*
 * 剑指offer 11 旋转数组的最小数字
 *
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。
 *
 * 示例 1：
 *
 * 输入：[3,4,5,1,2]
 * 输出：1
 *
 * 示例 2：
 *
 * 输入：[2,2,2,0,1]
 * 输出：0
 * */

#include <vector>

class Solution11 {
public:
    /*
     * 方法1 直接遍历 O(n)
     *
     * 设置第一个数为数组最小值min，
     * 从数组第二个数开始遍历数组，
     * 将v[i]与min进行比较，
     * 如果min大于v[i]，就将min设置为v[i]，
     * 返回最小值min
     * */
    int minArray(std::vector<int> &numbers);

    /*
     * 方法2 二分法 O(logn)
     *
     * 1. 使用mid = left + (rigth - left) / 2 防止数值过大溢出，
     * [特别好用的二分查找法模板]
     * (https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/)
     *
     * 2. 因为最小值右边的序列肯定是有序的，
     * 以mid与right的值进行大小比较,
     * 当mid比right值小，则下一轮在右边，
     * 当mid比right值大，则下一轮在在左边，
     * 当mid比right值等于，使用将right减1去掉可能的重复值。
     * */
    int minArray2(std::vector<int> &numbers);
};


#endif //SWORDTOOFFER_MINARRAY_H
