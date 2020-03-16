//
// Created by Wanhui on 3/12/20.
//

#include "TreeToDoublyList.h"

BiTreeNode *Solution36::treeToDoublyList(BiTreeNode *root) {
    if (root == nullptr) {
        return root;
    }

    BiTreeNode *lastNodeInList = nullptr;
    convertNode(root, &lastNodeInList);

    BiTreeNode *headOfList = lastNodeInList;

    while (headOfList != nullptr && headOfList->left != nullptr) {
        headOfList = headOfList->left;
    }

    lastNodeInList->right = headOfList;
    headOfList->left = lastNodeInList;

    return headOfList;
}

void Solution36::convertNode(BiTreeNode *node, BiTreeNode **lastNodeInList) {
    if (node == nullptr) {
        return;
    }

    BiTreeNode *curNode = node;

    if (curNode->left != nullptr) {
        convertNode(curNode->left, lastNodeInList);
    }

    curNode->left = *lastNodeInList;

    if (*lastNodeInList != nullptr) {
        (*lastNodeInList)->right = curNode;
    }

    *lastNodeInList = curNode;

    if (curNode->right != nullptr) {
        convertNode(curNode->right, lastNodeInList);
    }
}
