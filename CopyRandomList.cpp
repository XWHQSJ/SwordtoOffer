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
        copyNode->val = node->val;
        copyNode->next = node->next;
        copyNode->random = nullptr;

        node->next = copyNode;
        node = copyNode->next;
    }
}

void Solution35::connectRandomNode(Node *head) {
    Node* node = head;
    while (node != nullptr){
        Node* copyNode = node->next;

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

    if(node != nullptr){
        copyHead = node->next;
        copyNode = copyHead;
        node->next = copyNode->next;
        node = node->next;
    }

    while (node != nullptr){
        copyNode->next = node->next;
        copyNode = copyNode->next;
        node->next = copyNode->next;
        node = node->next;
    }

    return copyHead;
}
