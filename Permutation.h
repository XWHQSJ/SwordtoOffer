//
// Created by Wanhui on 2/27/20.
//

#ifndef SWORDTOOFFER_PERMUTATION_H
#define SWORDTOOFFER_PERMUTATION_H

/*
 * 剑指offer 38 字符串的排列
 *
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 *
 * 示例:
 *
 * 输入：s = "abc"
 * 输出：["abc","acb","bac","bca","cab","cba"]
 *
 * 限制：
 * 1 <= s 的长度 <= 8
 * */


#include <string>
#include <vector>

class Solution38 {
public:
    /*
     *
     *
     * */
    std::vector<std::string> permutation(std::string s);

    /*
     *
     * */
    void backtrack(std::vector<std::string> &res, std::string s, std::string &track, std::vector<bool> &visit);


    /*
     *
     *
     * */
    std::vector<std::string> permutation2(std::string s);

    /*
     *
     * */
    void backtrack2(std::string s, int start, std::set<std::string> &res)
};


#endif //SWORDTOOFFER_PERMUTATION_H
