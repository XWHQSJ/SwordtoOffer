//
// Created by Wanhui on 2/15/20.
//

#ifndef SWORDTOOFFER_BUILDTREE_H
#define SWORDTOOFFER_BUILDTREE_H

/*
 * 剑指offer 07 重建二叉树
 *
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 *
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 * 返回如下的二叉树：
 *    3
 *   / \
 *  9  20
 *     / \
 *    15  7
 *
 *    限制：
 *    0 <= 节点个数 <= 5000
 * */

#include <vector>

// Definition for a binary tree node.
struct BiTreeNode {
    int val;
    BiTreeNode *left;
    BiTreeNode *right;

    BiTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution07 {
public:
    /*
     * 方法1
     *
     * 二叉树前序遍历的第一个数必然是二叉树的根结点，
     * 在中序遍历中找到根结点的位置，
     * 那么中序遍历中根结点位置左边结点即二叉树的左子树结点的中序遍历，
     * 中序遍历根结点位置的右边结点即二叉树的右子树结点的中序遍历；
     * 先计算出左树结点数量c，
     * 则在前序遍历中根结点位置右边的c个结点即二叉树的左子树结点的前序遍历，
     * 前序遍历中剩下的结点即二叉树的右子树结点的前序遍历；
     * 根据数量c，将左子树结点的前序遍历，左子树结点的中序遍历，
     * 右子树结点的前序遍历，右子树结点的中序遍历分别存到四个数组中，
     * 再将此四个数组两两配对后进行递归，即可构建二叉树
     * */
    BiTreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder);

    /*
     * 方法2
     *
     * 方法2与原理相同，处理参数的方式略不同，
     * 但方法2的效率高于方法1，
     * 方法1由于数组存储消耗时间
     * */
    BiTreeNode *buildTree2(std::vector<int> &preorder, std::vector<int> &inorder);

    static BiTreeNode *
    build(std::vector<int> &preorder, int prestart, int preend, std::vector<int> &inorder, int instart, int inend);
};


#endif //SWORDTOOFFER_BUILDTREE_H
