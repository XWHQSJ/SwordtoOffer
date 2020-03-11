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
     * 队列+计数
     *
     * 跟32-I相同，都是二叉树按层遍历，但不同的是按层输出。
     * 每出队一个节点，就会将该节点的非空子节点入队，
     * 所以队列里在循环结束前都是有节点的。
     * 那么要按照层序来打印节点值，就需要对每层的节点数进行计数。
     * 设定记录下一层将要入队的子节点数为nextCount，
     * 设定本层还未出队的节点数levelCount。
     * 这样本层每出队一个节点，levelCount减一，每入队一个子节点，nextCount加一。
     * 当本层所有节点都出队，即levelCount等于0时，可以将本层的数存储到结果数组中。
     * 在开始新一轮的子节点遍历前，将nextCount赋值给levelCount作为新一轮的本层未出队节点数，
     * 将nextCount置0，重新开始计数再下一层的子节点数。
     * 重复上述操作，直到循环结束。
     * */
    std::vector<std::vector<int>> levelOrder(BiTreeNode *root);
};


#endif //SWORDTOOFFER_LEVELORDERII_H
