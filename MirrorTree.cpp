//
// Created by Wanhui on 3/4/20.
//

#include "MirrorTree.h"

BiTreeNode *Solution27::mirrorTree(BiTreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    // 如果左右子树为空时，返回根节点
    if (root->left == nullptr && root->right == nullptr) {
        return root;
    }

    // 交换左右子树
    BiTreeNode *tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;

    // 对左子树递归
    if (root->left) {
        mirrorTree(root->left);
    }

    // 对右子树递归
    if (root->right) {
        mirrorTree(root->right);
    }

    return root;
}
