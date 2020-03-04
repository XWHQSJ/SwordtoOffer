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
     * 递归遍历
     *
     * 先需要确定树A中是否存在树B的根节点，
     * 如果不存在则直接返回false，存在则继续判断该节点后的左右子树是否也完全相同，
     * 遍历树B结束都相同则返回true，不同返回false。
     * 这里需要有两次递归，第一次是递归从树A中找到等于树B根节点的节点，
     * 第二次递归是从相同的节点开始，对树的左右子树判断是否树A完全包含树B。
     * */
    bool isSubStructure(BiTreeNode* A, BiTreeNode* B);

    bool dfs(BiTreeNode* A, BiTreeNode* B);
};


#endif //SWORDTOOFFER_ISSUBSTRUCTURE_H
