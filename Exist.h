//
// Created by Wanhui on 2/17/20.
//

#ifndef SWORDTOOFFER_EXIST_H
#define SWORDTOOFFER_EXIST_H

/*
 * 剑指offer 12 矩阵中的路径
 *
 * 请设计一个函数，
 * 用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一格开始，
 * 每一步可以在矩阵中向左、右、上、下移动一格。
 * 如果一条路径经过了矩阵的某一格，
 * 那么该路径不能再次进入该格子。
 * 例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
 *
 * [["a","b","c","e"],
 * ["s","f","c","s"],
 * ["a","d","e","e"]]
 *
 * 但矩阵中不包含字符串“abfb”的路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
 * 路径不能再次进入这个格子。
 *
 * 示例 1：
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * 输出：true
 *
 * 示例 2：
 *
 * 输入：board = [["a","b"],["c","d"]], word = "abcd"
 * 输出：false
 *
 * 提示：
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * */

#include <vector>
#include <string>

class Solution12 {
public:
    /*
     * 类似于八皇后问题，比较简单的思路是，
     * 遍历board矩阵，从矩阵中找到与字符串第一个字符相等的值。
     * 从这个值开始，将其上下左右的值与字符串第二个字符进行比较，
     * 找到相等的值，如果不相等回溯到原值并从其他方向进行比较；
     * 重复上述的操作，直到找到字符串最后一个字符为止。
     * */
    bool exist(std::vector<std::vector<char>> &board, std::string word);

private:
    /*
     * 1. 当前值之后的下一轮操作，需要确定查询方向：
     * 上下左右{(x+1,y),(x-1,y),(x,y+1),(x,y-1)}
     *
     * 2. 对于已经遍历过的值，需要进行标记，
     * 通常的做法是设置标记数组，每次查询标记数组该值是否遍历过;
     * 一种比较好的方法是,
     * 直接将已经遍历过的值改为矩阵中不存在的值，最后恢复即可
     * */
    bool dfs(std::vector<std::vector<char>> &board, std::string word, int index, int x, int y);
};


#endif //SWORDTOOFFER_EXIST_H
