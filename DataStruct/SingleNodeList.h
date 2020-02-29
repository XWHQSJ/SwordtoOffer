//
// Created by Wanhui on 2/28/20.
//

#ifndef SWORDTOOFFER_SINGLEListNodeLIST_H
#define SWORDTOOFFER_SINGLEListNodeLIST_H

#include "Node.h"

class SingleListNodeList{
public:
    SingleListNodeList();
    ~SingleListNodeList();

    // 清除所有节点
    void clear();
    // 判断是否为空
    bool empty();
    // 链表元素数量
    int size();
    // 获取index处的元素
    int getElem(int index);
    // 获取节点的索引
    int locateElem(ListNode* node);
    // 遍历链表
    void traverse();
    // 插入节点
    void insert(int index, ListNode* ListNode);
    // 删除节点
    void remove(int index, ListNode* ListNode);
    // 从头插入节点
    void insertHead(ListNode* ListNode);
    // 从尾插入节点
    void insertTail(ListNode* ListNode);

private:
    // 头哨兵
    ListNode* mListNode;
    int mSize;
};

SingleListNodeList::SingleListNodeList() {
    mListNode = new ListNode(0);
    mSize = 0;
}

SingleListNodeList::~SingleListNodeList() {
    clear();
    delete mListNode;
    mSize = 0;
}

void SingleListNodeList::clear() {
    ListNode* curListNode = mListNode->next;
    while (curListNode != nullptr){
        ListNode* tempListNode = curListNode;
        delete curListNode;
        curListNode = tempListNode->next;
    }

    mListNode->next = nullptr;
}

bool SingleListNodeList::empty() {
    return 0 == mSize;
}

int SingleListNodeList::size() {
    return mSize;
}

int SingleListNodeList::getElem(int index) {
    if(index < 0 || index > mSize){
        return -1;
    }

    ListNode* curNode = mListNode;
    for(int i = 0; i < index; i++){
        curNode = curNode->next;
    }

    return curNode->val;
}

int SingleListNodeList::locateElem(ListNode *node) {
    ListNode* curNode = mListNode;
    int index = 0;
    while (curNode->next != nullptr){
        if(curNode->val == node->val){
            return index;
        }
        curNode = curNode->next;
        index++;
    }

    return -1;
}

void SingleListNodeList::traverse() {
    ListNode* curNode = mListNode;

    while (curNode->next != nullptr){
        curNode = curNode->next;
    }
}

void SingleListNodeList::insert(int index, ListNode *node) {
    if(index < 0 || index > mSize){
        return;
    }

    ListNode* curNode = mListNode;
    for(int i = 0; i < index; i++){
        curNode = curNode->next;
    }

    auto* newNode = new ListNode(0);
    newNode->val = node->val;
    newNode->next = curNode->next;
    curNode->next = newNode;
}

void SingleListNodeList::remove(int index, ListNode *node) {
    if(index < 0 || index > mSize){
        return;
    }

    node->val = node->next->val;
    node->next = node->next->next;
    mSize--;
}

void SingleListNodeList::insertHead(ListNode *node) {
    auto* newNode = new ListNode(0);

    ListNode* temp = mListNode->next;
    newNode->val = node->val;
    mListNode->next = newNode;
    newNode->next = temp;
    mSize++;
}

void SingleListNodeList::insertTail(ListNode *node) {
    ListNode* curNode = mListNode;
    while (curNode->next != nullptr){
        curNode = curNode->next;
    }

    auto* newNode = new ListNode(0);

    newNode->val = node->val;
    newNode->next = nullptr;
    curNode->next = newNode;
    mSize++;
}

#endif //SWORDTOOFFER_SINGLEListNodeLIST_H
