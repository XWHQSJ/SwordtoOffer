//
// Created by Wanhui on 3/22/20.
//

#include <algorithm>
#include "IsBalanced.h"

bool Solution55_2::isBalanced(BiTreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    // 递归左子树
    int leftDepth = maxDepth(root->left);
    // 递归右子树
    int rightDepth = maxDepth(root->right);

    // 左右子树深度差
    int diff = leftDepth - rightDepth;
    // 如果大于1则不平衡
    if (diff > 1 || diff < -1) {
        return false;
    }

    // 对左右子树进行递归判断
    return isBalanced(root->left) && isBalanced(root->right);
}

int Solution55_2::maxDepth(BiTreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    // 递归左子树
    int leftDepth = maxDepth(root->left);
    // 递归右子树
    int rightDepth = maxDepth(root->right);

    // 返回左右子树深度较大的值加1
    return std::max(leftDepth, rightDepth) + 1;
}


bool Solution55_2::isBalanced2(BiTreeNode *root) {
    int depth = 0;
    return balance(root, depth);
}

bool Solution55_2::balance(BiTreeNode *root, int &depth) {
    // 叶节点是平衡的，且深度为0
    if (root == nullptr) {
        depth = 0;
        return true;
    }

    // 定义左右子树的深度
    // 定义左右子树的深度差
    int left = 0, right = 0, diff = 0;

    // 如果该节点的左右子树是平衡的
    if (balance(root->left, left) && balance(root->right, right)) {
        // 则当前节点的左右子树根据返回的深度计算差
        diff = left - right;
        // 如果深度差小于1则是平衡的
        if (diff <= 1 && diff >= -1) {
            // 同时当前节点的深度为左右子树深度较大值加1
            depth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
}
