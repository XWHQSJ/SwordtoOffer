//
// Created by Wanhui on 3/10/20.
//

#include "SpiralOrder.h"

std::vector<int> Solution29::spiralOrder(std::vector<std::vector<int>> &matrix) {
    std::vector<int> ans;

    if (matrix.empty()) {
        return ans;
    }

    // 初始化上下边界，上下边界表示行数
    int up = 0, down = matrix.size() - 1;

    // 初始化左右边界，左右边界表示列数
    int left = 0, right = matrix[0].size() - 1;

    // 当上下左右边界满足条件时，不断循环
    while (up < matrix.size() && down >= 0 && left < matrix[0].size() && right >= 0) {
        // 上面行向右遍历
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[up][i]);
        }
        // 上边界up更新
        if (++up > down) {
            break;
        }

        // 右边列向下遍历
        for (int i = up; i <= down; i++) {
            ans.push_back(matrix[i][right]);
        }
        // 右边界right更新
        if (--right < left) {
            break;
        }

        // 下边行向左遍历
        for (int i = right; i >= left; i--) {
            ans.push_back(matrix[down][i]);
        }

        // 下边界更新
        if (--down < up) {
            break;
        }

        // 左边列向上遍历
        for (int i = down; i >= up; i--) {
            ans.push_back(matrix[i][left]);
        }

        // 左边界更新
        if (++left > right) {
            break;
        }
    }

    return ans;
}
