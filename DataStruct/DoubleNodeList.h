//
// Created by Wanhui on 2/24/20.
//

#ifndef SWORDTOOFFER_LISTNODE_H
#define SWORDTOOFFER_LISTNODE_H

#include "BiNode.h"
#include <stdexcept>
#include <cstddef>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

template <typename T>
class DoubleNodeList {
public:
    // 构造函数
    DoubleNodeList();
    // 拷贝构造函数
    DoubleNodeList(const DoubleNodeList& other);
    // 析构函数
    ~DoubleNodeList();

    // 判断链表是否为空
    bool empty() const;
    // 获取链表节点是数量
    std::size_t size() const;

    // 获得头节点
    T& front();
    // 获得尾节点
    T& back();
    // [] 像数组一样获得position处的节点
    T& operator[](std::size_t position);

    // 获得position处的节点
    T& at(std::size_t position);

    // 删除节点
    void erase(std::size_t position);
    // 插入节点
    void insert(std::size_t position, const T& value);

    // 从头节点处压入节点
    void push_front(const T& value);
    // 从尾节点处添加节点
    void push_back(const T& value);
    // 从头节点出弹出节点
    void pop_front();
    // 从尾节点出弹出节点
    void pop_back();

    // 清除所有节点
    void clear();
    // 给节点值排序（升序）
    void sort();

    // 按值删除节点
    void remove(const T& value);
    // = 像数值一样，赋值链表
    T& operator=(DoubleNodeList& other);
    // 赋值链表
    void assign(const DoubleNodeList& other);
    // 交换链表
    void swap(const DoubleNodeList& other);

private:
    // 找到position处的节点
    BiNode<T>* find(std::size_t position);
    // 在first与second中间插入值为value的节点
    void insert_between(BiNode<T> *first, BiNode<T> *second, const T& value);
    // 在first与second中间删除值为value的节点
    void remove_inner(BiNode<T> *first, BiNode<T> *second, BiNode<T> *third);

    // 链表节点数量
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
DoubleNodeList<T>::DoubleNodeList(const DoubleNodeList &other) : mSize(0), mHeadSentinel(new BiNode<T>()), mTailSentinel(new BiNode<T>()) {
    if(other.mHeadSentinel == nullptr){
        return;
    }

    BiNode<T> *tmp = other.mHeadSentinel;
    while (tmp != nullptr){
        push_back(tmp->mData);
        tmp = tmp->mNetx;
    }
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
    }

    return temp->mPrev;
}

template<typename T>
void DoubleNodeList<T>::insert_between(BiNode<T> *first, BiNode<T> *second, const T &value) {
    // location.prev = first = prev, location = second = next
    auto* temp = new BiNode<T>(value, second, first);

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

template<typename T>
void DoubleNodeList<T>::clear() {
    if(mSize == 0){
        return;
    }

    BiNode<T>* p = mHeadSentinel->mNetx;
    while (p != mTailSentinel){
        BiNode<T> *temp = p;
        p = p->mNetx;
        delete temp;
    }

    mHeadSentinel->mNetx = mTailSentinel;
    mTailSentinel->mPrev = mHeadSentinel;
    mSize = 0;
}

template<typename T>
void DoubleNodeList<T>::sort() {
    if(mSize <= 1){
        return;
    }

    BiNode<T>* p = mHeadSentinel->mNetx;

    for(int i = 0; i < mSize - 1; i++){
        BiNode<T> *q = p->mNetx;
        for(int j = i+1; j < mSize; j++){
            if(p->mData > q->mData){
                T temp = q->mData;
                q->mData = p->mData;
                p->mData = temp;
            }
            q = q->mNetx;
        }
        p = p->mNetx;
    }
}

template<typename T>
DoubleNodeList<T>::~DoubleNodeList() {
    if(mSize == 0){
        delete mHeadSentinel;
        delete mTailSentinel;
        mHeadSentinel = nullptr;
        mTailSentinel = nullptr;
        return;
    }

    while (mHeadSentinel->mNetx != nullptr){
        BiNode<T> *temp = mHeadSentinel;
        mHeadSentinel = mHeadSentinel->mNetx;
        delete temp;
    }

    delete mHeadSentinel;
    mHeadSentinel = nullptr;
}

template<typename T>
void DoubleNodeList<T>::remove(const T &value) {
    if(mHeadSentinel == mTailSentinel){
        return;
    }

    BiNode<T> *tmp = mHeadSentinel->mNetx;
    while (tmp != mTailSentinel){
        if(tmp->mData == value){
            remove_inner(tmp->mPrev, tmp, tmp->mNetx);
        }
        tmp = tmp->mNetx;
    }
}

template<typename T>
T &DoubleNodeList<T>::operator=(DoubleNodeList &other) {
    return assign(other);
}

template<typename T>
void DoubleNodeList<T>::assign(const DoubleNodeList &other) {
    if(this != &other){
        DoubleNodeList tmp(other);
        swap(tmp);
    }
}

template<typename T>
void DoubleNodeList<T>::swap(const DoubleNodeList &other) {
    std::swap(this->mHeadSentinel, other.mHeadSentinel);
    std::swap(this->mTailSentinel, other.mTailSentinel);
}


#endif //SWORDTOOFFER_LISTNODE_H
