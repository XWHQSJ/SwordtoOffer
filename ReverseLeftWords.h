//
// Created by Wanhui on 3/23/20.
//

#ifndef SWORDTOOFFER_REVERSELEFTWORDS_H
#define SWORDTOOFFER_REVERSELEFTWORDS_H

/*
 * 剑指offer 58-II 左旋转字符串
 *
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串左旋转操作的功能。
 * 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 *
 * 示例 1：
 *
 * 输入: s = "abcdefg", k = 2
 * 输出: "cdefgab"
 *
 * 示例 2：
 *
 * 输入: s = "lrloseumgh", k = 6
 * 输出: "umghlrlose"
 *
 * 限制：
 * 1 <= k < s.length <= 10000
 * */


#include <string>

class Solution58_2 {
public:
    /*
     * string 类特性
     *
     * 将前n个字符组成字符串添加到字符串s后面，再删除前面n个字符。
     * */
    std::string reverseLeftWords(std::string s, int n);

    /*
     * 三次原地翻转
     *
     * 将前n个字符与后面剩下的字符按照两个字符串，分别进行字符串翻转，再对整个字符串s进行翻转。
     *
     * 例如： s = abcdefg ;  k = 2 ---> s1 = bagfedc ---> s2 = cdefgab 左旋转成功
     * */
    std::string reverseLeftWords2(std::string s, int n);
};


#endif //SWORDTOOFFER_REVERSELEFTWORDS_H
