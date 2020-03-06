//
// Created by Wanhui on 3/6/20.
//

#ifndef SWORDTOOFFER_ISSYMMETRIC_H
#define SWORDTOOFFER_ISSYMMETRIC_H

/*
 * 剑指offer 28 对称的二叉树
 *
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。
 * 如果一棵二叉树和它的镜像一样，那么它是对称的。
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 *    1
 *   / \
 *  2   2
 *   \   \
 *   3    3
 *
 * 示例 1：
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 * 示例 2：
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 * 限制：
 * 0 <= 节点个数 <= 1000
 * */


#include <DataStruct/BiTreeNode.h>

class Solution28 {
public:
    /*
     * 方法1 递归法
     *
     * 对称二叉树如下：
     *     1
     *    / \
     *   2   2
     *  / \ / \
     * 3  4 4  3
     *
     * 由观察可以发现，根节点的左节点2与根节点的右节点2要相等，
     * 同时根节点左子树的左节点3与根节点右子树的右节点3相等，
     * 同时根节点左子树的右节点4与根节点右子树的左节点4相等。
     *
     * 所以只需要递归判断此上三个条件即可。
     * */
    bool isSymmetric(BiTreeNode *root);

    // 镜像函数，对比镜像对应的值
    bool isMirror(BiTreeNode *root1, BiTreeNode *root2);


    /*
     * 方法2 迭代法
     *
     * 利用队列先进先出的特性模拟方法1的递归操作，
     * 将根节点的左右子节点push到队列中，
     * 然后pop出来比较它们的值是否相等，
     * 再按照左子树的左节点，右子树的右节点，
     * 左子树的右节点，右子树的左节点顺序push到队列中。
     * */
    bool isSymmetric2(BiTreeNode *root);
};


#endif //SWORDTOOFFER_ISSYMMETRIC_H
