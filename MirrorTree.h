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
 * */


#include "DataStruct/BiTreeNode.h"

class Solution27 {
public:
    /*
     *
     *
     * */
    BiTreeNode* mirrorTree(BiTreeNode* root);
};


#endif //SWORDTOOFFER_MIRRORTREE_H
