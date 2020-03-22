//
// Created by Wanhui on 3/22/20.
//

#ifndef SWORDTOOFFER_ISBALANCED_H
#define SWORDTOOFFER_ISBALANCED_H

/*
 * 剑指offer 55-II 平衡二叉树
 *
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
 * 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *
 * 示例 1:
 *
 * 给定二叉树 [3,9,20,null,null,15,7]
 *       3
 *      / \
 *     9  20
 *       /  \
 *      15   7
 *
 * 返回 true 。
 *
 * 示例 2:
 *
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 *       1
 *      / \
 *     2   2
 *    / \
 *   3   3
 *  / \
 * 4   4
 *
 * 返回 false 。
 *
 * 限制：
 * 1 <= 树的结点个数 <= 10000
 * */


#include <DataStruct/BiTreeNode.h>

class Solution55_2 {
public:
    bool isBalanced(BiTreeNode* root);
};


#endif //SWORDTOOFFER_ISBALANCED_H
