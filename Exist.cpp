//
// Created by Wanhui on 2/17/20.
//

#include "Exist.h"

bool Solution12::exist(std::vector<std::vector<char>> &board, std::string word) {
    if (board.empty()) {
        return false;
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Solution12::dfs(std::vector<std::vector<char>> &board, std::string word, int index, int x, int y) {
    //判断是否越界和是否继续递归
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) {
        return false;
    }

    //递归结束
    if (index == word.size() - 1) {
        return true;
    }

    //直接改变矩阵中的值，防止重复搜索
    //比使用mark[][]数组存储访问标志要简单
    char tmp = board[x][y];
    board[x][y] = '.';

    //递归查找，查询的四个方向：上下左右{(x+1,y),(x-1,y),(x,y+1),(x,y-1)}
    if (dfs(board, word, index + 1, x, y + 1)
        || dfs(board, word, index + 1, x, y - 1)
        || dfs(board, word, index + 1, x + 1, y)
        || dfs(board, word, index + 1, x - 1, y)) {
        return true;
    }
    //恢复为原值
    board[x][y] = tmp;

    return false;
}
