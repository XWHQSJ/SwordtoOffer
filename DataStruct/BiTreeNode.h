//
// Created by Wanhui on 3/1/20.
//

#ifndef SWORDTOOFFER_BITREENODE_H
#define SWORDTOOFFER_BITREENODE_H

template<typename T>
struct BiTreeNode{
    // 节点中存储的数据
    T data;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode(int x) : data(x), left(nullptr), right(nullptr){}
};

#endif //SWORDTOOFFER_BITREENODE_H
