//
// Created by Wanhui on 3/11/20.
//

#ifndef SWORDTOOFFER_LEVELORDER_H
#define SWORDTOOFFER_LEVELORDER_H

/*
 * 剑指offer 32-I 从上到下打印二叉树
 *
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 *
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * 返回：
 * [3,9,20,15,7]
 *
 * 提示：
 * 节点总数 <= 1000
 * */


#include "DataStruct/BiTreeNode.h"
#include <vector>

class Solution32_1 {
public:
    /*
     * 队列法
     *
     * 因为要对二叉树进行层序遍历，所以不能使用递归方法。
     * 可以使用队列先进先出的特点对节点进行处理。
     * 先将根节点进队，取队首节点存入结果数组中，出队；
     * 如果根节点的左右子节点都不为空，则将左节点和右节点按顺序入队，
     * 依次取队首加入结果数组，再判断该节点的左右子节点是否为空，
     * 不为空则入队。重复上述操作，直到队列为空。
     * */
    std::vector<int> levelOrder(BiTreeNode *root);
};


#endif //SWORDTOOFFER_LEVELORDER_H
