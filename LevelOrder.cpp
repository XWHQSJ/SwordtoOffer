//
// Created by Wanhui on 3/11/20.
//

#include <deque>
#include "LevelOrder.h"

std::vector<int> Solution32_1::levelOrder(BiTreeNode *root) {
    if (root == nullptr) {
        return {};
    }

    // 结果数组
    std::vector<int> ans;

    // 存储二叉树节点的队列
    std::deque<BiTreeNode *> deq;

    // 先将根节点入队
    deq.push_back(root);

    // 队列不为空时循环
    while (!deq.empty()) {
        // 取队首元素
        BiTreeNode *popNode = deq.front();
        // 将队首元素加入结果数组
        ans.push_back(popNode->val);

        // 判断出队的队首节点的左节点是否为空，
        // 不为空则入队
        if (popNode->left != nullptr) {
            deq.push_back(popNode->left);
        }

        // 判断出队的队首节点的右节点是否为空，
        // 不为空则入队
        if (popNode->right != nullptr) {
            deq.push_back(popNode->right);
        }

        // 队首元素出队
        deq.pop_front();
    }

    return ans;
}
