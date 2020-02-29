//
// Created by Wanhui on 2/28/20.
//

#ifndef SWORDTOOFFER_SINGLEListNodeLIST_H
#define SWORDTOOFFER_SINGLEListNodeLIST_H

#include "Node.h"

class SingleNodeList {
public:
    SingleNodeList();

    ~SingleNodeList();

    // 清除所有节点
    void clear();

    // 判断是否为空
    bool empty();

    // 链表元素数量
    int size();

    // 获取index处的元素
    int getElem(int index);

    // 获取节点的索引
    int locateElem(ListNode *node);

    // 遍历链表
    void traverse();

    // 插入节点
    void insert(int index, ListNode *ListNode);

    // 删除节点
    void remove(int index, ListNode *ListNode);

    // 从头插入节点
    void insertHead(ListNode *ListNode);

    // 从尾插入节点
    void insertTail(ListNode *ListNode);

private:
    // 头哨兵
    ListNode *mListNode;
    int mSize;
};

SingleNodeList::SingleNodeList() {
    mListNode = new ListNode(0);
    mSize = 0;
}

SingleNodeList::~SingleNodeList() {
    clear();
    delete mListNode;
    mSize = 0;
}

void SingleNodeList::clear() {
    ListNode *curListNode = mListNode->next;
    while (curListNode != nullptr) {
        ListNode *tempListNode = curListNode;
        delete curListNode;
        curListNode = tempListNode->next;
    }

    mListNode->next = nullptr;
}

bool SingleNodeList::empty() {
    return 0 == mSize;
}

int SingleNodeList::size() {
    return mSize;
}

int SingleNodeList::getElem(int index) {
    if (index < 0 || index > mSize) {
        return -1;
    }

    ListNode *curNode = mListNode;
    for (int i = 0; i < index; i++) {
        curNode = curNode->next;
    }

    return curNode->val;
}

int SingleNodeList::locateElem(ListNode *node) {
    ListNode *curNode = mListNode;
    int index = 0;
    while (curNode->next != nullptr) {
        if (curNode->val == node->val) {
            return index;
        }
        curNode = curNode->next;
        index++;
    }

    return -1;
}

void SingleNodeList::traverse() {
    ListNode *curNode = mListNode;

    while (curNode->next != nullptr) {
        curNode = curNode->next;
    }
}

void SingleNodeList::insert(int index, ListNode *node) {
    if (index < 0 || index > mSize) {
        return;
    }

    ListNode *curNode = mListNode;
    for (int i = 0; i < index; i++) {
        curNode = curNode->next;
    }

    auto *newNode = new ListNode(0);
    newNode->val = node->val;
    newNode->next = curNode->next;
    curNode->next = newNode;
}

void SingleNodeList::remove(int index, ListNode *node) {
    if (index < 0 || index > mSize) {
        return;
    }

    node->val = node->next->val;
    node->next = node->next->next;
    mSize--;
}

void SingleNodeList::insertHead(ListNode *node) {
    auto *newNode = new ListNode(0);

    ListNode *temp = mListNode->next;
    newNode->val = node->val;
    mListNode->next = newNode;
    newNode->next = temp;
    mSize++;
}

void SingleNodeList::insertTail(ListNode *node) {
    ListNode *curNode = mListNode;
    while (curNode->next != nullptr) {
        curNode = curNode->next;
    }

    auto *newNode = new ListNode(0);

    newNode->val = node->val;
    newNode->next = nullptr;
    curNode->next = newNode;
    mSize++;
}

#endif //SWORDTOOFFER_SINGLEListNodeLIST_H
