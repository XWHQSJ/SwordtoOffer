//
// Created by Wanhui on 3/11/20.
//

#ifndef SWORDTOOFFER_LEVELORDERII_H
#define SWORDTOOFFER_LEVELORDERII_H

/*
 * 剑指offer 32-II 从上到下打印二叉树II
 *
 * 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
 *
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 * 返回其层次遍历结果：
 *
 * [
 *     [3],
 *     [9,20],
 *     [15,7]
 * ]
 *
 * 提示：
 * 节点总数 <= 1000
 * */


#include <DataStruct/BiTreeNode.h>
#include <vector>

class Solution32_2 {
public:
    /*
     *
     * */
    std::vector<std::vector<int>> levelOrder(BiTreeNode* root)
};


#endif //SWORDTOOFFER_LEVELORDERII_H
