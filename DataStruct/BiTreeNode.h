//
// Created by Wanhui on 3/1/20.
//

#ifndef SWORDTOOFFER_BITREENODE_H
#define SWORDTOOFFER_BITREENODE_H

template<typename T>
struct BiTreeNode{
    // 节点中存储的数据
    T data;

    // 左子树和右子树
    BiTreeNode<T> *leftChild;
    BiTreeNode<T> *rightChild;

    // 不带参数构造函数
    BiTreeNode() : leftChild(nullptr), rightChild(nullptr){}

    // 带默认值的有参数构造函数
    BiTreeNode(T x, BiTreeNode<T> *l = nullptr, BiTreeNode<T> *r = nullptr) : data(x), leftChild(l), rightChild(r){}
};

#endif //SWORDTOOFFER_BITREENODE_H
