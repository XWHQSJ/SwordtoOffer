//
// Created by Wanhui on 3/11/20.
//

#include <deque>
#include <algorithm>
#include "LevelOrderIII.h"

std::vector<std::vector<int>> Solution32_3::levelOrder(BiTreeNode *root) {
    if (root == nullptr) {
        return {};
    }

    // 存放数组的数组
    std::vector<std::vector<int>> ans;
    // 存放每一层的节点数组
    std::vector<int> levelAns;
    // 存放节点的队列
    std::deque<BiTreeNode *> deq;

    // 将根节点入队
    deq.push_back(root);
    // 初始化下一层节点数
    int nextCount = 0;
    // 初始化本层未出队节点数
    int levelCount = 1;
    // 初始化当前的层数
    int level = 0;

    while (!deq.empty()) {
        BiTreeNode *popNode = deq.front();
        levelAns.push_back(popNode->val);

        // 左节点入队，下一层节点数加一
        if (popNode->left != nullptr) {
            deq.push_back(popNode->left);
            nextCount++;
        }

        // 右节点入队，下一层节点数加一
        if (popNode->right != nullptr) {
            deq.push_back(popNode->right);
            nextCount++;
        }

        // 本层节点出队，本层未出队节点数减一
        deq.pop_front();
        levelCount--;

        // 本层节点全部出队时
        if (levelCount == 0) {
            // 如果当前层是奇数时，
            // 对该层的数组元素进行反转
            if (level & 1) {
                // 对本层节点反转
                std::reverse(std::begin(levelAns), std::end(levelAns));
            }

            // 本层结束后，层数加1
            level++;

            // 将本层全部节点存入结果数组
            ans.push_back(levelAns);
            // 将本层数组置空
            levelAns = {};
            // 将下一层的节点数赋给本层，
            // 重新开始新的一轮
            levelCount = nextCount;

            // 下一轮的子节点数重新开始计数
            nextCount = 0;
        }
    }

    return ans;
}
