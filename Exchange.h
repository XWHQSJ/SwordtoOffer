//
// Created by Wanhui on 2/20/20.
//

#ifndef SWORDTOOFFER_EXCHANGE_H
#define SWORDTOOFFER_EXCHANGE_H

/*
 * 剑指offer 21 调整数组顺序使奇数位于偶数前面
 *
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 *
 * 示例：
 *
 * 输入：nums = [1,2,3,4]
 * 输出：[1,3,2,4]
 * 注：[3,1,2,4] 也是正确的答案之一。
 *
 * 提示：
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10000
 * */


#include <vector>

class Solution21 {
public:
    /*
     * 方法1 同侧指针法
     * 双指针lo为交换指针，cur是遍历指针，
     * 他们从同一侧开始移动，
     * 当为偶数时，双指针同时移动，并做交换操作
     * 当遍历指针指向奇数时，
     * 遍历指针移动，交换指针不移动
     * */
    std::vector<int> exchange(std::vector<int>& nums);


    /*
     * 方法2 两侧指针法
     * 双指针low为左侧指针，high为右侧指针，
     * 两指针分别从左右两侧开始遍历，
     * 当左侧指针指向偶数时，low指针向右移动，
     * 当右侧指针指向奇数时，high指针向左移动，
     * 当low指向奇数，同时high指向偶数时，进行交换操作
     * */
    std::vector<int> exchange2(std::vector<int>& nums);


    /*
     * 方法3 空间换时间
     * 增加数组oarr，使用空间换时间
     * 先遍历数组arr将偶数取出存入oarr中，
     * 再遍历一遍数据arr将奇数取出存入oarr中,
     * 其中c和r是用于记录存入oarr中的数据量的，
     * 目的是内存操作正确
     * */
    std::vector<int> exchange3(std::vector<int>& nums);
};


#endif //SWORDTOOFFER_EXCHANGE_H
