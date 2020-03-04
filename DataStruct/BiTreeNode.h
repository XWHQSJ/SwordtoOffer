//
// Created by Wanhui on 3/1/20.
//

#ifndef SWORDTOOFFER_BITREENODE_H
#define SWORDTOOFFER_BITREENODE_H


// Definition for a binary tree node.
struct BiTreeNode {
    int val;
    BiTreeNode *left;
    BiTreeNode *right;

    BiTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //SWORDTOOFFER_BITREENODE_H
