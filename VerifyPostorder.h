//
// Created by Wanhui on 3/12/20.
//

#ifndef SWORDTOOFFER_VERIFYPOSTORDER_H
#define SWORDTOOFFER_VERIFYPOSTORDER_H

/*
 * 剑指offer 33 二叉搜索树的后序遍历序列
 *
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
 * 如果是则返回 true，否则返回 false。
 * 假设输入的数组的任意两个数字都互不相同。
 *
 * 参考以下这颗二叉搜索树：
 *
 *     5
 *    / \
 *   2   6
 *  / \
 * 1   3
 *
 * 示例 1：
 *
 * 输入: [1,6,3,2,5]
 * 输出: false
 *
 * 示例 2：
 *
 * 输入: [1,3,2,6,5]
 * 输出: true
 *
 * 提示：
 * 数组长度 <= 1000
 * */


#include <vector>

class Solution33 {
public:
    /*
     * 递归判断
     *
     * 二叉搜索树是右子树的节点大于根节点，根节点大于左子树的节点，
     * 则二叉搜索树的后序遍历数组，最后一个数是根节点的值，
     * 根节点左边大于根节点的值是右子树节点的值，小于根节点的值是左子树节点的值。
     *
     * 根据上述二叉搜索树的特点，可以使用递归方法对后序遍历二叉树的数组进行判断。
     * 先从左往右遍历数组，当数值小于根节点的数值时，指针右移，此时遍历的是左子树的节点。
     * 直到找到第一个大于根节点的值，跳出循环，记录此时的索引 i 。
     * 从第一个大于根节点的值开始右移指针，当遍历到小于根节点的值时，
     * 表示不是二叉搜索树，返回false，若无则继续遍历。
     *
     * 因为索引 i 处的值是第一个大于根节点的值，所以该处左边是左子树的节点，
     * 右边不包括根节点是右子树的节点。这样就可以划分出左子树和右子树，
     * 分别按照上述的过程进行递归判断。
     * */
    bool verifyPostorder(std::vector<int> &postorder);

    bool helper(std::vector<int> &postorder, int start, int end);

};


#endif //SWORDTOOFFER_VERIFYPOSTORDER_H
