//
// Created by Wanhui on 3/10/20.
//

#include <algorithm>
#include "MaxDepth.h"

int Solution55_1::maxDepth(BiTreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    // 递归左子树
    int leftDepth = maxDepth(root->left);
    // 递归右子树
    int rightDepth = maxDepth(root->right);

    // 返回左右子树深度较大的值加1
    return std::max(leftDepth, rightDepth) + 1;

    // 将上述三步总结为一句返回
//    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
