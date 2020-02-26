//
// Created by Wanhui on 2/26/20.
//

#ifndef SWORDTOOFFER_NODE_H
#define SWORDTOOFFER_NODE_H

template<typename T>
class Node {
public:
    Node();

    Node(const T &data, Node *next, Node *prev);

    T mData;
    Node *mNetx;
    Node *mPrev;
};

template<typename T>
Node<T>::Node() : mData(), mNetx(nullptr), mPrev(nullptr) {}

template<typename T>
Node<T>::Node(const T &data, Node *next, Node *prev) : mData(data), mNetx(next), mPrev(prev) {}

#endif //SWORDTOOFFER_NODE_H
