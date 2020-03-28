//
// Created by Wanhui on 3/28/20.
//

#include "LowestCommonAncestor.h"

BiTreeNode *Solution68_1::lowestCommonAncestor(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q) {
    if (root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }

    // 使用差乘的正负判断是否父节点是否在两节点之间，
    // 减少判断次数
    if (((root->val - q->val) * (root->val - p->val)) <= 0) {
        return root;
    }

    // 因为p和q要么比root大，要么比root小，
    // 所以只需要将父节点与一个节点比较即可
    // 如果两节点都比父节点小，遍历左子树
    if (p->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // 如果两节点都比父节点大，遍历右子树
    if (p->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return nullptr;
}
