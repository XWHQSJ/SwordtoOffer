//
// Created by Wanhui on 3/10/20.
//

#ifndef SWORDTOOFFER_SPIRALORDER_H
#define SWORDTOOFFER_SPIRALORDER_H

/*
 * 剑指offer 29 顺时针打印矩阵
 *
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 *
 * 示例 1：
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 * 示例 2：
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 * 限制：
 * 0 <= matrix.length <= 100
 * 0 <= matrix[i].length <= 100
 * */


#include <vector>

class Solution29 {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
};


#endif //SWORDTOOFFER_SPIRALORDER_H
