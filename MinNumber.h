//
// Created by Wanhui on 3/19/20.
//

#ifndef SWORDTOOFFER_MINNUMBER_H
#define SWORDTOOFFER_MINNUMBER_H

/*
 * 剑指offer 45 把数组排成最小的数
 *
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。
 *
 * 示例 1:
 *
 * 输入: [10,2]
 * 输出: "102"
 *
 * 示例 2:
 *
 * 输入: [3,30,34,5,9]
 * 输出: "3033459"
 *
 * 提示:
 * 0 < nums.length <= 100
 *
 * 说明:
 * 输出结果可能非常大，所以你需要返回一个字符串而不是整数
 * 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
 * */


#include <string>
#include <vector>

class Solution45 {
public:
    /*
     * 排序法
     *
     * 定义一种排序规则，假设对于两个数m和n，如果 mn < nm，则认为m小于n，
     * 相反如果 nm < mn，则认为n < m（这里的小于是人为定义的小于，不是数学意义上的）。
     * 又因为直接拼接数字，可能会使拼接的数字溢出，因此将nums中的数转化为字符串，
     * 在对字符串拼接进行比较: s1 + s2 < s2 + s1。利用该小于的比较规则，
     * 将字符串数组重新排序后，拼接字符串数组中的字符串即可。
     * */
    std::string minNumber(std::vector<int> &nums);

    static bool compare(std::string &s1, std::string &s2);
};


#endif //SWORDTOOFFER_MINNUMBER_H
