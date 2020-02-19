//
// Created by Wanhui on 2/19/20.
//

#include <malloc.h>
#include "DeleteNode.h"

ListNode *Solution18::deleteNode(ListNode *head, int val) {
    ListNode* node = head;
    ListNode* node1 = head;
    int c = 0, i = 0;
    while (node->val != val){
        node = node->next;
        c++;
    }
    node = node->next;

    if(c == 0){
        head = head->next;
        return head;
    }

    while (i < c-1){
        node1 = node1->next;
        i++;
    }

    node1->next = node;

    return head;
}
