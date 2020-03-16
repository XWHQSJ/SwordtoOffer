//
// Created by Wanhui on 3/12/20.
//

#include "TreeToDoublyList.h"

BiTreeNode *Solution36::treeToDoublyList(BiTreeNode *root) {
    if (root == nullptr) {
        return root;
    }

    // 已排序链表的最后一个节点
    BiTreeNode *lastNodeInList = nullptr;

    // 对二叉搜索树进行有序双向链表的转化
    convertNode(root, &lastNodeInList);

    // 将有序双向链表的的最后一个节点赋值为链表的头节点
    BiTreeNode *headOfList = lastNodeInList;

    // 对有序双向链表向前遍历到链表的头部
    while (headOfList != nullptr && headOfList->left != nullptr) {
        headOfList = headOfList->left;
    }

    // 此时有序双向链表还不是循环的，
    // 所以需要将该链表的头节点的前驱指向链表尾节点，
    // 将链表的尾节点的后继指向链表的头节点构成循环双向链表
    lastNodeInList->right = headOfList;
    headOfList->left = lastNodeInList;

    return headOfList;
}

void Solution36::convertNode(BiTreeNode *node, BiTreeNode **lastNodeInList) {
    if (node == nullptr) {
        return;
    }

    // 遍历的当前节点
    BiTreeNode *curNode = node;

    // 如果当前节点不为左叶节点，就递归遍历到最左叶节点
    if (curNode->left != nullptr) {
        convertNode(curNode->left, lastNodeInList);
    }

    // 将当前节点添加到有序双向链表中

    // 当前节点的左指针指向已排序的双向链表的最后一个节点,
    // 即当前节点的前驱是已排序的双向链表的最后一个节点
    curNode->left = *lastNodeInList;

    // 已排序的双向链表的最后一个节点的右指针指向当前节点，
    // 即已排序的双向链表的最后一个节点的后继是当前节点
    if (*lastNodeInList != nullptr) {
        (*lastNodeInList)->right = curNode;
    }

    // 更新有序双向链表的最后一个节点为当前节点
    *lastNodeInList = curNode;

    // 继续对当前节点的右子树进行递归遍历
    if (curNode->right != nullptr) {
        convertNode(curNode->right, lastNodeInList);
    }
}
