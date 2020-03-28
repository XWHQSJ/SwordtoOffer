//
// Created by Wanhui on 3/28/20.
//

#ifndef SWORDTOOFFER_LOWESTCOMMONANCESTOR_H
#define SWORDTOOFFER_LOWESTCOMMONANCESTOR_H

/*
 * 剑指offer 68-I 二叉搜索树的最近公共祖先
 *
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
 * 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 * 见图： binarysearchtree_improved.png
 * 示例 1:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 *
 * 示例 2:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 *
 * 说明:
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉搜索树中。
 * */


#include <DataStruct/BiTreeNode.h>

class Solution68_1 {
public:
    /*
     * 递归遍历
     *
     * 因为二叉搜索树的性质是左节点的值小于根节点的值小于右节点的值，
     * 而最低公共祖先节点的值必然在两给定节点值中间，包括两端。
     * 所以将父节点的值与给定两节点的值进行比较：
     * 1. 如果父节点值在两节点值中间，返回父节点；
     * 2. 如果两节点值都大于父节点值，则遍历右子树；
     * 3. 如果两节点值都小于父节点值，则遍历左子树。
     * */
    BiTreeNode *lowestCommonAncestor(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q);
};


#endif //SWORDTOOFFER_LOWESTCOMMONANCESTOR_H
