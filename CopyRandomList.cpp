//
// Created by Wanhui on 2/25/20.
//

#include "CopyRandomList.h"

Node *Solution35::copyRandomList(Node *head) {
    if(head == nullptr){
        return head;
    }

    copyNodes(head);
    connectRandomNode(head);

    return splitCopyNodeList(head);
}

void Solution35::copyNodes(Node *head) {
    Node* node = head;

    while (node != nullptr){
        Node* copyNode = new Node(0);
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
    Node* node = head;

    while (node != nullptr){
        Node* copyNode = node->next;
        // 复制random指针
        if(node->random != nullptr){
            copyNode->random = node->random->next;
        }

        node = copyNode->next;
    }
}

Node *Solution35::splitCopyNodeList(Node *head) {
    Node* node = head;
    Node* copyHead = nullptr;
    Node* copyNode = nullptr;

    // 因为是返回拆分后的链表
    // 所以先要将原链表第一个节点拆除
    if(node != nullptr){
        copyHead = node->next;
        copyNode = copyHead;
        node->next = copyNode->next;
        node = node->next;
    }

    // 拆出复制的链表
    while (node != nullptr){
        copyNode->next = node->next;
        copyNode = copyNode->next;
        node->next = copyNode->next;
        node = node->next;
    }

    return copyHead;
}
