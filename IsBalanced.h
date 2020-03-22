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
    /*
     * 递归法 -- 节点多次遍历
     *
     * 先递归计算左右子树的深度，判断左右子树是否平衡，如果左右深度差大于1则不平衡。
     * 如果平衡，再对左右子树的左右子树进行递归判断是否平衡。
     * 这样存在的问题是，在计算左右子树深度时已经遍历过二叉树左右子树的左右子树，
     * 所以这样计算会导致多次对二叉树节点进行遍历，增加开销。
     * */
    bool isBalanced(BiTreeNode* root);

    // 计算二叉树的深度
    int maxDepth(BiTreeNode *root);


    /*
     * 递归法 -- 节点单次遍历
     *
     * 为避免对二叉树的节点进行多次遍历，可以在遍历二叉树的过程中就计算二叉树的深度。
     * 因为后序遍历在访问每个节点前就已经遍历过它的左右子树。只要在遍历每个节点时，
     * 记录该节点的深度，即该节点到叶节点路径的深度，就可以边遍历边判断每个节点是否是平衡的。
     * */
    bool isBalanced2(BiTreeNode* root);

    // 判断节点是否平衡
    bool balance(BiTreeNode* root, int& depth);
};


#endif //SWORDTOOFFER_ISBALANCED_H
