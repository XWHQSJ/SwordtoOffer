//
// Created by Wanhui on 3/12/20.
//

#ifndef SWORDTOOFFER_TREETODOUBLYLIST_H
#define SWORDTOOFFER_TREETODOUBLYLIST_H

/*
 * 剑指offer 36 二叉搜索树与双向链表
 *
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
 * 要求不能创建任何新的节点，只能调整树中节点指针的指向。
 * 为了让您更好地理解问题，以下面的二叉搜索树为例：
 *
 * 见图 二叉搜索树与双向链表1.png
 *
 * 我们希望将这个二叉搜索树转化为双向循环链表。
 * 链表中的每个节点都有一个前驱和后继指针。
 * 对于双向循环链表，第一个节点的前驱是最后一个节点，
 * 最后一个节点的后继是第一个节点。
 * 下图展示了上面的二叉搜索树转化成的链表。
 * “head” 表示指向链表中有最小元素的节点。
 *
 * 见图 二叉搜索树与双向链表2.png
 *
 * 特别地，我们希望可以就地完成转换操作。
 * 当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
 * 还需要返回链表中的第一个节点的指针。
 * */


#include <DataStruct/BiTreeNode.h>

class Solution36 {
public:
    /*
     * 转换后的链表是有序的双向循环链表，而二叉树有左右两指针与双向链表的前后驱相对应。
     * 又由二叉搜索树左节点<根节点<右节点的特性，可以使用中序遍历二叉树的每个节点。
     * 因为中序遍历算法的特点是按照从小到大的顺序遍历二叉树的每个节点。
     * 当遍历到根节点时，将二叉搜索树分为3个部分：根节点，左子树，右子树。
     * 根绝有序循环链表的定义，根节点将链接在左子树中值最大的节点后，同时在右子树值最小的节点前。
     * 按照中序遍历的顺序，当遍历转换到根节点时，它的左子树已经转换为一个有序的双向链表了，
     * 并且处在链表中最后一个节点是当前值最大的节点。当将根节点链接在该节点后，根节点成为最大节点。
     * 接着遍历转换右子树的节点，最后将根节点作为右子树中值最小的节点的前驱。
     * */
    BiTreeNode *treeToDoublyList(BiTreeNode *root);

    // 中序遍历二叉搜索树
    void convertNode(BiTreeNode *node, BiTreeNode **lastNodeInList);
};


#endif //SWORDTOOFFER_TREETODOUBLYLIST_H