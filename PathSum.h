//
// Created by Wanhui on 3/12/20.
//

#ifndef SWORDTOOFFER_PATHSUM_H
#define SWORDTOOFFER_PATHSUM_H

/*
 * 剑指offer 34 二叉树中和为某一值的路径
 *
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 * 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
 *
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 *
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \    / \
 * 7    2  5   1
 *
 * 返回:
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 *
 * 提示：
 * 节点总数 <= 10000
 * */


#include <DataStruct/BiTreeNode.h>
#include <vector>

class Solution34 {
public:
    /*
     * 存储路径节点法
     * 因为是计算二叉树根节点到叶节点路径上节点值的和，
     * 可以使用前序遍历对二叉树进行遍历。
     *
     * 但问题是访问路径的和不一定等于目标值sum，
     * 所以需要将该路径的所有点存储起来，如果该路径的和不等于sum，
     * 则从叶节点开始回溯。递归的方法本身含有回溯的操作，
     * 所以我们需要做的就是怎么存储路径上的节点。
     *
     * 因为需要存储节点和删除节点的操作，所以使用栈是好的结构。
     * 但又需要对路径和等于sum的路径节点进行存储返回，
     * 所以改使用std::vector，同样能进行尾部添加和删除操作。
     * 同时使用全局变量，方便对正确路径节点进行返回。
     *
     * 1. 访问根节点，将根节点的值累加到当前路径和curSum；
     * 2. 判断当前节点是否为叶节点，如果当前节点是叶节点，
     *    且根节点到当前叶节点路径和curSum等于sum，
     *    则将该路径上的节点存入结果数组中。
     *    接着弹出该叶节点，对二叉树其他节点继续遍历，找到其他正确的路径。
     * 3. 如果当前节点是非叶节点，它的左子节点不为空则递归遍历其左子树，
     *    它的右子节点不为空则递归遍历其右子树。
     * 4. 继续步骤1,2的操作，依次类推。
     * */
    std::vector<std::vector<int>> pathSum(BiTreeNode *root, int sum);

    void findPath(BiTreeNode *root, int sum, std::vector<int> &path, int curSum);

private:
    std::vector<std::vector<int>> ans;
    std::vector<int> pathAns;
};


#endif //SWORDTOOFFER_PATHSUM_H
