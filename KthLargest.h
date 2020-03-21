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
    /*
     * 后序遍历
     *
     * 因为二叉搜索树左节点小于根节点小于右节点的特性，
     * 可以使用后序遍历的方式将所有节点按照从大到小的方式排序。
     * 在排序的过程中，因为是第k大，所以直接取第k个节点的值即可。
     * */
    int kthLargest(BiTreeNode *root, int k);

    // 递归后序遍历
    void dfs(BiTreeNode *root, int &k, int &ans);
};


#endif //SWORDTOOFFER_KTHLARGEST_H
