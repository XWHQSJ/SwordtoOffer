//
// Created by Wanhui on 2/26/20.
//

#ifndef SWORDTOOFFER_BINODE_H
#define SWORDTOOFFER_BINODE_H

template<typename T>
class BiNode {
public:
    BiNode();

    BiNode(const T &data, BiNode *next, BiNode *prev);

    T mData;
    BiNode *mNetx;
    BiNode *mPrev;
};

template<typename T>
BiNode<T>::BiNode() : mData(), mNetx(nullptr), mPrev(nullptr) {}

template<typename T>
BiNode<T>::BiNode(const T &data, BiNode *next, BiNode *prev) : mData(data), mNetx(next), mPrev(prev) {}

#endif //SWORDTOOFFER_BINODE_H
