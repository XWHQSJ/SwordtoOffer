//
// Created by Wanhui on 2/24/20.
//

#ifndef SWORDTOOFFER_LISTNODE_H
#define SWORDTOOFFER_LISTNODE_H

#include "Node.h"
#include <stdexcept>
#include <cstddef>

template <typename T>
class NodeList {
public:
    NodeList();

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
    void pop_fron();
    void pop_back();

    void clear();
    void sort();

    void remove(const T& value);
    void assign(const NodeList& other);
    void swap(const NodeList& other);

private:
    Node<T>* find(std::size_t position);
    void insert_between(Node<T> *first, Node<T> *second, const T& value);
    void remove_inner(Node<T> *first, Node<T> *second, Node<T> *third);

    std::size_t mSize;
    // 头哨兵
    Node<T>* mHeadSentinel;
    // 尾哨兵
    Node<T>* mTailSentinel;
};

template<typename T>
NodeList<T>::NodeList() {

}

template<typename T>
bool NodeList<T>::empty() const {
    return false;
}

template<typename T>
std::size_t NodeList<T>::size() const {
    return 0;
}

template<typename T>
T &NodeList<T>::front() {
    return <#initializer#>;
}


#endif //SWORDTOOFFER_LISTNODE_H
