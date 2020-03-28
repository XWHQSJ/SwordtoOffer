//
// Created by Wanhui on 3/28/20.
//


#include "LowestCommonAncestorOfBiTree.h"

BiTreeNode *Solution68_2::lowestCommonAncestor(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root == p || root == q) {
        return root;
    }

    BiTreeNode *left = lowestCommonAncestor(root->left, p, q);
    BiTreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr) {
        return right;
    }

    if (right == nullptr) {
        return left;
    }

    return root;
}

BiTreeNode *Solution68_2::lowestCommonAncestor2(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q) {
    return nullptr;
}

BiTreeNode *Solution68_2::lowestCommonAncestor3(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q) {
    return nullptr;
}
