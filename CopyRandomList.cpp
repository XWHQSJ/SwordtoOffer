//
// Created by Wanhui on 2/25/20.
//

#include <map>
#include "CopyRandomList.h"

Node *Solution35::copyRandomList(Node *head) {
    if (head == nullptr) {
        return head;
    }

    copyNodes(head);
    connectRandomNode(head);

    return splitCopyNodeList(head);
}

void Solution35::copyNodes(Node *head) {
    Node *node = head;

    while (node != nullptr) {
        Node *copyNode = new Node(0);
        // 复制节点
        copyNode->val = node->val;
        copyNode->next = node->next;
        copyNode->random = nullptr;

        // 将复制节点挂在原节点后
        node->next = copyNode;
        node = copyNode->next;
    }
}

void Solution35::connectRandomNode(Node *head) {
    Node *node = head;

    while (node != nullptr) {
        Node *copyNode = node->next;
        // 复制random指针
        if (node->random != nullptr) {
            copyNode->random = node->random->next;
        }

        node = copyNode->next;
    }
}

Node *Solution35::splitCopyNodeList(Node *head) {
    Node *node = head;
    Node *copyHead = nullptr;
    Node *copyNode = nullptr;

    // 因为是返回拆分后的链表
    // 所以先要将原链表第一个节点拆除
    if (node != nullptr) {
        copyHead = node->next;
        copyNode = copyHead;
        node->next = copyNode->next;
        node = node->next;
    }

    // 拆出复制的链表
    while (node != nullptr) {
        copyNode->next = node->next;
        copyNode = copyNode->next;
        node->next = copyNode->next;
        node = node->next;
    }

    return copyHead;
}


Node *Solution35::copyRandomList2(Node *head) {
    if (head == nullptr) {
        return head;
    }

    std::map<Node *, Node *> visited;
    visited[nullptr] = nullptr;

    Node *prev = nullptr;
    Node *node = head;

    // 建立原链表的哈希表，
    // 使用map存储原节点与复制节点的对应关系
    while (node != nullptr) {
        Node *newNode = new Node(head->val);
        visited[node] = newNode;
        node = node->next;
    }

    // 重置node节点
    node = head;

    // 复制链表的每个节点
    while (node != nullptr) {
        // 从复制链表的第一个节点开始
        // newNode作为临时节点
        Node *newNode = visited[node];

        // 复制节点的value和random指针
        newNode->val = node->val;
        newNode->random = visited[node->random];
        newNode->next = nullptr;

        // 连接复制链表的每个节点
        // 复制next指针
        if (prev != nullptr) {
            visited[prev]->next = newNode;
        }

        prev = node;
        node = node->next;
    }

    return visited[head];
}


Node *Solution35::copyRandomList3(Node *head) {
    std::map<Node *, Node *> visited;

    if (head == nullptr) {
        return head;
    }

    // 回溯结束条件
    if (visited.count(head)) {
        return visited[head];
    }

    // 复制节点且复制值
    Node *node = new Node(head->val);

    // 做选择
    visited[head] = node;

    // 进入下一层决策
    // 复制next和random指针
    node->next = copyRandomList3(head->next);
    node->random = copyRandomList3(head->random);


    return node;
}





















