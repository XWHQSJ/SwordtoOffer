//
// Created by Wanhui on 3/18/20.
//

#ifndef SWORDTOOFFER_FIRSTUNIQCHAR_H
#define SWORDTOOFFER_FIRSTUNIQCHAR_H

/*
 * 剑指offer 50 第一个只出现依次的字符
 *
 * 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
 *
 * 示例:
 *
 * s = "abaccdeff"
 * 返回 "b"
 *
 * s = ""
 * 返回 " "
 *
 * 限制：
 * 0 <= s 的长度 <= 50000
 * */


#include <string>

class Solution50 {
public:
    /*
     * 哈希表法
     *
     * 使用哈希表存储字符串中的每个字符及对应出现的次数，
     * 再次遍历字符串中的字符，判断该字符的次数是否为1，
     * 当为1时即返回该字符，始终找不到则返回空字符。
     * */
    char firstUniqChar(std::string s);
};


#endif //SWORDTOOFFER_FIRSTUNIQCHAR_H
