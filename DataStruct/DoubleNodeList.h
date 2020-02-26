//
// Created by Wanhui on 2/24/20.
//

#ifndef SWORDTOOFFER_LISTNODE_H
#define SWORDTOOFFER_LISTNODE_H

#include "BiNode.h"
#include <stdexcept>
#include <cstddef>

template <typename T>
class DoubleNodeList {
public:
    DoubleNodeList();

    bool empty() const;
    std::size_t size() const;

    T& front();
    T& back();
    T& operator[](std::size_t position);
    T& at(std::size_t position);

    void erase(std::size_t position);
    void insert(std::size_t position, const T& value);

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();

    void clear();
    void sort();

    void remove(const T& value);
    void assign(const DoubleNodeList& other);
    void swap(const DoubleNodeList& other);

private:
    BiNode<T>* find(std::size_t position);
    void insert_between(BiNode<T> *first, BiNode<T> *second, const T& value);
    void remove_inner(BiNode<T> *first, BiNode<T> *second, BiNode<T> *third);

    std::size_t mSize;
    // 头哨兵
    BiNode<T>* mHeadSentinel;
    // 尾哨兵
    BiNode<T>* mTailSentinel;
};

template<typename T>
DoubleNodeList<T>::DoubleNodeList() : mSize(0), mHeadSentinel(new BiNode<T>()), mTailSentinel(new BiNode<T>()) {
    mHeadSentinel->mNetx = mTailSentinel;
    mTailSentinel->mPrev = mHeadSentinel;
}

template<typename T>
bool DoubleNodeList<T>::empty() const {
    return mSize == 0;
}

template<typename T>
std::size_t DoubleNodeList<T>::size() const {
    return mSize;
}

template<typename T>
T &DoubleNodeList<T>::front() {
    return mHeadSentinel->mNetx->mData;
}

template<typename T>
T &DoubleNodeList<T>::back() {
    return mTailSentinel->mPrev->mData;
}

template<typename T>
T &DoubleNodeList<T>::operator[](std::size_t position) {
    return at(position);
}

template<typename T>
T &DoubleNodeList<T>::at(std::size_t position){
    BiNode<T>* location = find(position);
    return location->mData;
}

template<typename T>
void DoubleNodeList<T>::erase(std::size_t position) {
    BiNode<T>* location = find(position);

    // 删除内部节点
    remove_inner(location->mPrev, location, location->mNetx);
    --mSize;
}

template<typename T>
void DoubleNodeList<T>::insert(std::size_t position, const T &value) {
    BiNode<T> *location = find(position);

    // 插入内部节点
    insert_between(location->mPrev, location, value);
    ++mSize;
}

template<typename T>
void DoubleNodeList<T>::push_front(const T &value) {
    // 在头哨兵与头节点间插入
    // 相当于从链头push节点
    insert_between(mHeadSentinel, mHeadSentinel->mNetx, value);
    ++mSize;
}

template<typename T>
void DoubleNodeList<T>::push_back(const T &value) {
    insert_between(mTailSentinel->mPrev, mTailSentinel, value);
    ++mSize;
}

template<typename T>
void DoubleNodeList<T>::pop_front() {
    // 在头哨兵与第二个节点间删除头节点
    remove_inner(mHeadSentinel, mHeadSentinel->mNetx, mHeadSentinel->mNetx->mNetx);
    --mSize;
}

template<typename T>
void DoubleNodeList<T>::pop_back() {
    remove_inner(mTailSentinel->mPrev->mPrev, mTailSentinel->mPrev, mTailSentinel);
    --mSize;
}

template<typename T>
void DoubleNodeList<T>::clear() {

}

template<typename T>
void DoubleNodeList<T>::sort() {

}

template<typename T>
void DoubleNodeList<T>::remove(const T &value) {

}

template<typename T>
void DoubleNodeList<T>::assign(const DoubleNodeList &other) {

}

template<typename T>
void DoubleNodeList<T>::swap(const DoubleNodeList &other) {

}

template<typename T>
BiNode<T> *DoubleNodeList<T>::find(std::size_t position) {
    BiNode<T>* temp = nullptr;

    // 如果position在链表的前半部分
    // 则在链表的前半部分查找
    if(position <= mSize/2){
        temp = mHeadSentinel;
        while (position--) {
            temp = temp->mNetx;
            return temp->mNetx;
        }
    }

    // 如果poisition在链表的后半部分，
    // 则在链表的后半部分查找
    position = (mSize - 1) - position;

    temp = mTailSentinel;
    while (position--){
        temp = temp->mPrev;
        return temp->mPrev;
    }
}

template<typename T>
void DoubleNodeList<T>::insert_between(BiNode<T> *first, BiNode<T> *second, const T &value) {
    // location.prev = first = prev, location = second = next
    BiNode<T>* temp = new BiNode<T>(value, second, first);

    // location.prev.next = temp
    first->mNetx = temp;

    // location.prev = temp
    second->mPrev = temp;
}

template<typename T>
void DoubleNodeList<T>::remove_inner(BiNode<T> *first, BiNode<T> *second, BiNode<T> *third) {
    // location = second
    delete second;

    // location.next = third
    first->mNetx = third;
    // location.pre = first
    third->mPrev = first;
}


#endif //SWORDTOOFFER_LISTNODE_H
