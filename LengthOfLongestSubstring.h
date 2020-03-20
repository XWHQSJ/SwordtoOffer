//
// Created by Wanhui on 3/20/20.
//

#ifndef SWORDTOOFFER_LENGTHOFLONGESTSUBSTRING_H
#define SWORDTOOFFER_LENGTHOFLONGESTSUBSTRING_H

/*
 * 剑指offer 48 最长不含重复字符的子字符串
 *
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 * 提示：
 * s.length <= 40000
 * */


#include <string>

class Solution48 {
public:
    /*
     * 滑动窗口
     *
     * 设定滑动窗口的头部preIdx和尾部(当前字符s[i])，分情况进行处理：
     * 1. 如果当前字符的重复字符不在滑动窗口内，比较前一最长长度和当前最长长度，取最大值
     * 2. 如果当前字符的重复字符在滑动窗口内，更新头部preIdx，指向当前字符的重复字符的后一位置。
     * */

    // 滑动窗口实现1
    // 使用std::unordered_set存储字符
    int lengthOfLongestSubstring(std::string s);

    // 滑动窗口实现2
    // 使用std::unordered_map存储字符和对应在字符串中的索引
    int lengthOfLongestSubstring2(std::string s);


    /*
     * 动态规划
     *
     * 定义函数f(i)为以第i个字符结尾的不包含重复字符的子串的最长长度。
     * 当计算第i个字符当前的最长子串长度f(i)时，已经知道f(i-1)的值。
     * 可以分几种情况：
     * 1. 如果第i个字符未出现过或不包括在长度为f(i-1)的字符子串内，
     * 则状态转移方程为： f(i) = f(i-1) + 1
     * 2. 如果第i个字符在长度为f(i-1)的字符子串内，则需要将起始位置设为该字符后一个位置，
     *    计算此时的字符索引与该位置的距离： f(i) = i - preIdx
     * */
    int lengthOfLongestSubstring3(std::string s);
};


#endif //SWORDTOOFFER_LENGTHOFLONGESTSUBSTRING_H
