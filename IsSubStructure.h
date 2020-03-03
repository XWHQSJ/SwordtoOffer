//
// Created by Wanhui on 3/1/20.
//

#ifndef SWORDTOOFFER_ISSUBSTRUCTURE_H
#define SWORDTOOFFER_ISSUBSTRUCTURE_H

/*
 * 剑指offer 26 树的子结构
 *
 * 输入两棵二叉树A和B，判断B是不是A的子结构。
 * (约定空树不是任意一个树的子结构)
 * B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 *
 * 例如:
 * 给定的树 A:
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *
 * 给定的树 B：
 *      4
 *     /
 *    1
 * 返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
 *
 * 示例 1：
 *
 * 输入：A = [1,2,3], B = [3,1]
 * 输出：false
 *
 * 示例 2：
 *
 * 输入：A = [3,4,5,1,2], B = [4,1]
 * 输出：true
 *
 * 限制：
 * 0 <= 节点个数 <= 10000
 * */


#include "DataStruct/BiTreeNode.h"

/*
 * Definition for a binary tree node.
 * struct BiTreeNode {
 *     int val;
 *     BiTreeNode *left;
 *     BiTreeNode *right;
 *     BiTreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * */
class Solution26 {
public:
    /*
     *
     *
     * */
    bool isSubStructure(BiTreeNode<int>* A, BiTreeNode<int>* B);

    bool dfs(BiTreeNode<int>* A, BiTreeNode<int>* B);
};


#endif //SWORDTOOFFER_ISSUBSTRUCTURE_H
