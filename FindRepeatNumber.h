//
// Created by Wanhui on 2/12/20.
//

#ifndef SWORDTOOFFER_FINDREPEATNUMBER_H
#define SWORDTOOFFER_FINDREPEATNUMBER_H

/*
 * 剑指offer 03 数组中重复的数字
 *
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，
 * 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 *
 * 示例 1：
 * 输入：
 * [2, 3, 1, 0, 2, 5, 3]
 *
 * 输出：
 * 2 或 3
 *
 * 限制：
 * 2 <= n <= 100000
 * */


#include <vector>

class Solution03 {
public:
    /*
     * 方法1 桶排序
     * 使用空间换时间的策略，
     * 将nums[i]存储在数组vec的第i位置，
     * 当多次出现时，数组i位置的数vec[i]++，
     * 最后遍历存储数组vec，返回vec[i]>1的下标i
     * 时间复杂度O(n)，空间复杂度O(max(nums))
     * */
    int findRepeatNumber(std::vector<int> &nums);

    /*
     * 方法2 哈希表
     * 先使用C++中的unorder_map建立哈希表,
     * 使用循环将数据插入到哈希表中,
     * nums[i]是key,i是value,
     * 当同一个key对应的value > 1时,
     * 则返回该key
     * 时间复杂度O(n),空间复杂度O(n)
     * */
    int findRepeatNumber2(std::vector<int> &nums);

    /*
     * 方法3 排序法++
     * 使用通用排序算法将数据排序好后再遍历
     * 但通用排序算法的时间复杂度最快也只能达到O(nlogn)<快速排序,归并排序和堆排序>
     * 所以使用基于归并排序的最新设计的quadsort排序方法
     * 该方法源于github : https://github.com/scandum/quadsort/blob/master/quadsort.c
     * 排序时间复杂度可达到O(n)
     * */
    int findRepeatNumber3(std::vector<int> &nums);
};


#endif //SWORDTOOFFER_FINDREPEATNUMBER_H
