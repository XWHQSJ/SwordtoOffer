//
// Created by Wanhui on 2/15/20.
//

#include "BuildTree.h"

BiTreeNode *Solution07::buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {

    // WARNing : 注意边界情况！
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    // struct TreeNode有构造函数可以直接使用
    auto *root = new BiTreeNode(preorder[0]);

    int n = preorder.size();
    // WARNing : 注意边界情况！
    if (n == 1) {
        return root;
    }

    int c = 0, i = 0;
    std::vector<int> preleft, preright;
    std::vector<int> inleft, inright;

    for (i = 0; i < n; i++) {
        if (preorder[0] == inorder[i]) {
            c = i;
            break;
        }
    }

    // WARNing : 存储数组时注意下标
    for (i = 0; i < c; i++) {
        preleft.push_back(preorder[i + 1]);
        inleft.push_back(inorder[i]);
    }

    for (i = c + 1; i < n; i++) {
        preright.push_back(preorder[i]);
        inright.push_back(inorder[i]);
    }

    root->left = buildTree(preleft, inleft);
    root->right = buildTree(preright, inright);

    return root;
}

BiTreeNode *Solution07::buildTree2(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

BiTreeNode *
Solution07::build(std::vector<int> &preorder, int prestart, int preend, std::vector<int> &inorder, int instart,
                  int inend) {
    auto *root = new BiTreeNode(preorder[prestart]);

    int n = preorder.size();
    if (n == 1) {
        return root;
    }

    // 与方法1求根结点的方式不同，
    // 因为参数一直在变化
    int i = instart;
    while (i < inend && preorder[prestart] != inorder[i]) {
        i++;
    }

    int leftlen = i - instart;
    int rightlen = inend - i;

    // WARNing : 传入的参数画图进行确定，要准确
    if (leftlen > 0) {
        root->left = build(preorder, prestart + 1, prestart + leftlen, inorder, instart, instart + leftlen - 1);
    }

    if (rightlen > 0) {
        root->right = build(preorder, prestart + leftlen + 1, preend, inorder, instart + leftlen + 1, inend);
    }

    return root;
}
