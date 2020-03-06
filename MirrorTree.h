//
// Created by Wanhui on 3/4/20.
//

#ifndef SWORDTOOFFER_MIRRORTREE_H
#define SWORDTOOFFER_MIRRORTREE_H

/*
 * 剑指offer 27 二叉树的镜像
 *
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 *
 * 例如输入：
 *         4
 *       /   \
 *      2     7
 *     / \   / \
 *    1   3 6   9
 *
 * 镜像输出：
 *         4
 *       /   \
 *      7     2
 *     / \   / \
 *    9   6 3   1
 *
 * 示例 1：
 *
 * 输入：root = [4,2,7,1,3,6,9]
 * 输出：[4,7,2,9,6,3,1]
 *
 * 限制：
 * 0 <= 节点个数 <= 1000
 *
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，
 * 但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
 * */


#include "DataStruct/BiTreeNode.h"

class Solution27 {
public:
    /*
     * 递归遍历法
     *
     * 原始的二叉树如下：
     *         4
     *       /   \
     *      2     7
     *     / \   / \
     *    1   3 6   9
     *
     * 对根节点的左右子树交换后如下：
     *    --------->
     *
     *         4
     *       /   \
     *      7     2
     *     / \   / \
     *    6   9 1   3
     *
     * 对根节点的左右子树的左右子树进行递归后交换如下：
     *    --------->
     *
     *         4
     *       /   \
     *      7     2
     *     / \   / \
     *    9   6 3   1
     *
     * 如上二叉树的递归交换过程，只需要先对根节点的左右子树交换，
     * 在对根节点的左右子树递归遍历后，对其左右子树的左右子树交换即可。
     * */
    BiTreeNode *mirrorTree(BiTreeNode *root);
};


#endif //SWORDTOOFFER_MIRRORTREE_H
