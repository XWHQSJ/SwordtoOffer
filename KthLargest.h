//
// Created by Wanhui on 3/21/20.
//

#ifndef SWORDTOOFFER_KTHLARGEST_H
#define SWORDTOOFFER_KTHLARGEST_H

/*
 * 剑指 offer 54 二叉搜索数的第k大节点
 *
 * 给定一棵二叉搜索树，请找出其中第k大的节点。
 *
 * 示例 1:
 *
 * 输入: root = [3,1,4,null,2], k = 1
 *      3
 *     / \
 *    1   4
 *     \
 *      2
 * 输出: 4
 *
 * 示例 2:
 *
 * 输入: root = [5,3,6,2,4,null,null,1], k = 3
 *       5
 *      / \
 *     3   6
 *    / \
 *   2   4
 *  /
 * 1
 * 输出: 4
 *
 * 限制：
 * 1 ≤ k ≤ 二叉搜索树元素个数
 * */


#include <DataStruct/BiTreeNode.h>

class Solution54 {
public:
    int kthLargest(BiTreeNode* root, int k);
};


#endif //SWORDTOOFFER_KTHLARGEST_H
