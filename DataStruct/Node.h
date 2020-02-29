//
// Created by Wanhui on 2/28/20.
//

#ifndef SWORDTOOFFER_NODE_H
#define SWORDTOOFFER_NODE_H

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


// Definition for a Node
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#endif //SWORDTOOFFER_NODE_H
