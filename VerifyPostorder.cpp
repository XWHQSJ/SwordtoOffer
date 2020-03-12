//
// Created by Wanhui on 3/12/20.
//

#include "VerifyPostorder.h"

bool Solution33::verifyPostorder(std::vector<int> &postorder) {
    if (postorder.empty()) {
        return true;
    }

    return helper(postorder, 0, postorder.size() - 1);
}

bool Solution33::helper(std::vector<int> &postorder, int start, int end) {
    // 根节点是数组的最后一个值
    int root = postorder[end];

    // 从数组左边开始，
    // 小于根节点的值是左子树的节点，
    // 当遇到第一个大于根节点的值，
    // 跳出当前循环，记录索引 i
    int i = start;
    while (postorder[i] < root) {
        i++;
    }

    // 从索引 i 处继续向右遍历，
    // 向右是右子树的节点，
    // 如果遇到小于根节点的值，
    // 则表明不是二叉搜索树，返回false
    int j = i;
    while (j < end) {
        if (postorder[j] < root) {
            return false;
        }

        j++;
    }

    // 如果左右子树可以按照索引 i 划分，
    // 将左子树部分进行递归判断
    // start是起始索引，i-1是结束索引
    bool leftTree = true;
    if (i > start) {
        leftTree = helper(postorder, start, i - 1);
    }

    // 将右子树部分进行递归判断
    // 不包括根节点，
    // i是起始索引，end-1是结束索引
    bool rightTree = true;
    if (i < end - 1) {
        rightTree = helper(postorder, i, end - 1);
    }

    return leftTree && rightTree;
}

