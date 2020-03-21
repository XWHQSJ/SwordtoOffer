//
// Created by Wanhui on 3/21/20.
//

#include "KthLargest.h"

int Solution54::kthLargest(BiTreeNode *root, int k) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    dfs(root, k, ans);

    return ans;
}

void Solution54::dfs(BiTreeNode *root, int &k, int &ans) {
    // 右节点不为空时，递归右子树
    if (root->right != nullptr) {
        dfs(root->right, k, ans);
    }

    // 当右子树递归到叶节点，
    // 每递归返回一个节点就将k减一
    k--;

    // 直到找到第k大的节点
    if (k == 0) {
        ans = root->val;
    }

    // 如果在右子树为找到第k大的节点，
    // 就对左子树递归查找
    if (root->left != nullptr && k > 0) {
        dfs(root->left, k, ans);
    }
}
