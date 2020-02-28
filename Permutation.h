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
#include <set>
#include <vector>

class Solution38 {
public:
    /*
     * 回溯法
     *
     * 字符串的排列和数字的排列都属于回溯的经典问题
     *
     * 回溯算法框架：解决一个问题，实际上就是一个决策树的遍历过程：
     * 1. 路径：做出的选择
     * 2. 选择列表：当前可以做的选择
     * 3. 结束条件：到达决策树底层，无法再做选择的条件
     *
     * 伪代码：
     * result = []
     * def backtrack(路径，选择列表):
     *     if 满足结束条件：
     *         result.add(路径)
     *         return
     *     for 选择 in 选择列表:
     *         做选择
     *         backtrack(路径，选择列表)
     *         撤销选择
     *
     * 核心是for循环中的递归，在递归调用之前“做选择”，
     * 在递归调用之后“撤销选择”。
     *
     * 字符串的排列可以抽象为一棵决策树：
     *                       [ ]
     *          [a]          [b]         [c]
     *      [ab]   [ac]  [bc]   [ba]  [ca]  [cb]
     *     [abc]  [acb] [bca]  [bac]  [cab] [cba]
     *
     * 考虑字符重复情况：
     *                       [ ]
     *          [a]          [a]         [c]
     *      [aa]   [ac]  [ac]   [aa]  [ca]  [ca]
     *     [aac]  [aca] [aca]  [aac]  [caa] [caa]
     *
     * 字符串在做排列时，等于从a字符开始，对决策树进行遍历，
     * "a"就是路径，"b""c"是"a"的选择列表，"ab"和"ac"就是做出的选择，
     * “结束条件”是遍历到树的底层，此处为选择列表为空。
     *
     * 本题定义backtrack函数像一个指针，在树上遍历，
     * 同时维护每个点的属性，每当走到树的底层，其“路径”就是一个全排列。
     * 当字符出现重复，且重复位置不一定时，需要先对字符串进行排序，
     * 再对字符串进行“去重”处理，之后按照回溯框架即可。
     * */
    std::vector<std::string> permutation(std::string s);

    /*
     * 回溯函数
     * 使用sort函数对字符串排序，使重复的字符相邻，
     * 使用visit数组记录遍历决策树时每个节点的状态，
     * 节点未遍历且相邻字符不是重复字符时，
     * 则将该字符加入排列字符串中，依次递归遍历。
     * */
    void backtrack(std::vector<std::string> &res, std::string s, std::string &track, std::vector<bool> &visit);


    /*
     * 交换法 —— 回溯算法
     *
     * [a, [b, c]]
     * [b, [a, c]] [c, [b, a]]
     *
     * 如上，对字符串"abc"分割，每次固定一个字符为一部分，
     * 其他字符为另一部分，再将固定字符与其他字符进行交换，
     * 依次遍历每个字符，再进行回溯递归。
     * */
    std::vector<std::string> permutation2(std::string s);

    /*
     * 回溯函数
     * 使用set函数对字符串字符进行去重，
     * 使用swap函数交换两个字符
     * */
    void backtrack2(std::string s, int start, std::set<std::string> &res);
};


#endif //SWORDTOOFFER_PERMUTATION_H
