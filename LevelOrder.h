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
     *
     * */
    std::vector<int> levelOrder(BiTreeNode* root);
};


#endif //SWORDTOOFFER_LEVELORDER_H
