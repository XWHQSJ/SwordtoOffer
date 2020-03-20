//
// Created by Wanhui on 3/20/20.
//

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "LengthOfLongestSubstring.h"

int Solution48::lengthOfLongestSubstring(std::string s) {
    if (s.empty()) {
        return 0;
    }

    if (s.length() == 1) {
        return 1;
    }

    std::unordered_set<char> unorderedSet;

    // 最长子串长度
    int maxLen = 0;

    // 滑动窗口的头部，
    // 始终指向重复字符后一位置
    int preIdx = 0;

    // 遍历字符串字符
    for (int i = 0; i < s.length(); i++) {
        // 当前字符在哈希表中有相同字符
        while (unorderedSet.find(s[i]) != unorderedSet.end()) {
            // 从字符串开始删除字符，直到重复的字符也一并删除
            unorderedSet.erase(s[preIdx]);
            // 指向下一个字符，直到重复字符后一位置，
            // 即新滑动窗口的头部
            preIdx++;
        }

        // 不断插入不同字符到哈希表中，
        // 当重复字符被删后，更新该重复字符的在哈希表中的位置
        unorderedSet.insert(s[i]);
        // 更新子串长度为当前最长，
        // 当前索引减去重复字符索引
        maxLen = std::max(maxLen, i - preIdx + 1);
    }

    return maxLen;
}

int Solution48::lengthOfLongestSubstring2(std::string s) {
    if (s.empty()) {
        return 0;
    }

    if (s.length() == 1) {
        return 1;
    }

    int maxLen = 0;

    // 滑动窗口的头部，
    // 始终指向重复字符后一位置
    int preIdx = 0;

    // 存储字符串的字符及对应在字符串中的位置
    std::unordered_map<char, int> unorderedMap;

    for (int i = 0; i < s.length(); i++) {
        // 当前字符在哈希表中找到相同字符
        if (unorderedMap.find(s[i]) != unorderedMap.end()) {
            // 指向下一个字符，直到重复字符后一位置，
            // 即新滑动窗口的头部
            preIdx = std::max(preIdx, unorderedMap[s[i]] + 1);
        }

        // 更新重复字符的索引
        unorderedMap[s[i]] = i;

        // 更新子串长度为当前最长，
        // 当前索引减去重复字符索引
        maxLen = std::max(maxLen, i - preIdx + 1);
    }

    return maxLen;
}


int Solution48::lengthOfLongestSubstring3(std::string s) {
    if (s.empty()) {
        return 0;
    }

    if (s.length() == 1) {
        return 1;
    }

    // 返回的最大子串长度
    int maxLen = 0;

    // 滑动窗口的头部，
    // 始终指向重复字符后一位置
    int preIdx = 0;

    // 记录字符最近一次出现的位置
    std::vector<int> pos(128, -1);

    // 动态规划的状态数组
    std::vector<int> dp(s.length(), 0);

    // 初始化状态数组为1，
    // 有一个字符时长度为1
    dp[0] = 1;

    // 字符串首字符位置为1，依此类推
    pos[s[0]] = 0;

    for (int i = 1; i < s.length(); i++) {
        // 如果s[i]最近一次出现的位置在preIdx的左侧，
        // 表示当前指针preIdx到s[i]之间没有出现重复元素
        if (pos[s[i]] < preIdx) {
            // 当前最长子串长度等于前一个字符最长子串长度加一
            dp[i] = dp[i - 1] + 1;
        } else {
            // 如果s[i]最近一次出现的位置在preIdx与s[i]之间，
            // 则将preIdx跳跃到s[i]最近一次出现的位置，
            // 更新滑动窗口的头部(当前是新滑动窗口头部的前一位置)
            // 注意：此时s[i]的字符并没有记录在pos数组中
            preIdx = pos[s[i]];
            // 当前子串的最大长度为当前索引减去重复的字符的位置索引
            dp[i] = i - preIdx;
            // 更新preIdx指向重复字符的下一个位置
            preIdx++;
        }

        // 更新s[i]处的字符的位置为当前字符索引
        pos[s[i]] = i;

        // 更新最长子串长度
        maxLen = std::max(maxLen, dp[i]);
    }

    return maxLen;
}
