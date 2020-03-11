//
// Created by Wanhui on 3/11/20.
//

#ifndef SWORDTOOFFER_LEVELORDERIII_H
#define SWORDTOOFFER_LEVELORDERIII_H

/*
 * 剑指offer 32-III 从上到下打印二叉树III
 *
 * 请实现一个函数按照之字形顺序打印二叉树，
 * 即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
 * 第三行再按照从左到右的顺序打印，其他行以此类推。
 *
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 *
 * 返回其层次遍历结果：
 * [
 *    [3],
 *    [20,9],
 *    [15,7]
 * ]
 *
 * 提示：
 * 节点总数 <= 1000
 * */


#include <DataStruct/BiTreeNode.h>
#include <vector>

class Solution32_3 {
public:
    /*
     * 队列+计数+层数
     *
     * 与32-II相同，使用队列存储节点，计数进行层序遍历。
     * 本题不同的是在奇数层进行反序打印，那么只需要判断该层是奇数层，
     * 并将该层元素反转在存入结果数组即可。
     * */
    std::vector<std::vector<int>> levelOrder(BiTreeNode* root);
};


#endif //SWORDTOOFFER_LEVELORDERIII_H
