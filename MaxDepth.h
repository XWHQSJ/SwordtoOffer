//
// Created by Wanhui on 3/10/20.
//

#ifndef SWORDTOOFFER_MAXDEPTH_H
#define SWORDTOOFFER_MAXDEPTH_H

/*
 * 剑指offer 55-I 二叉树的深度
 *
 * 输入一棵二叉树的根节点，求该树的深度。
 * 从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，
 * 最长路径的长度为树的深度。
 *
 * 例如：
 *
 * 给定二叉树 [3,9,20,null,null,15,7]，
 *     3
 *    / \
 *   9  20
 *  /  \
 * 15   7
 *
 * 返回它的最大深度 3 。
 *
 * 提示：
 * 节点总数 <= 10000
 * */


#include <DataStruct/BiTreeNode.h>

class Solution55_1 {
public:
    /*
     * 递归法
     *
     * 二叉树的深度即从二叉树根节点到子节点最长路径的长度，
     * 如果二叉树只有一个根节点，则深度为1；
     * 如果根节点只有左子树，则左子树的深度加1；
     * 如果根节点只有右子树，则右子树的深度加1；
     * 如果根节点有左右子树，则选择左右子树中深度较大的加1。
     * 二叉树的深度通过递归遍历取得，当递归到叶子节点后，
     * 递归栈开始弹出，每弹出一个节点，则深度加1。
     * */
    int maxDepth(BiTreeNode* root);
};


#endif //SWORDTOOFFER_MAXDEPTH_H
