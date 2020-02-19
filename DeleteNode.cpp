//
// Created by Wanhui on 2/19/20.
//

#include <malloc.h>
#include "DeleteNode.h"

ListNode *Solution18::deleteNode(ListNode *head, int val) {

    if(!head){
        return nullptr;
    }

    ListNode node(0);
    node.next = head;

    if(head->val == val){
        head = head->next;
        return head;
    }

    while (head->next){
        if(head->next->val == val){
            head->next = head->next->next;
            break;
        }
        head = head->next;
    }

    return node.next;
}

ListNode *Solution18::deleteNode(ListNode *head, ListNode *node) {
    if(!head || !node){
        return nullptr;
    }

    if(head->val == node->val) {
        head = head->next;
        return head;
    }

    //使用下一节点覆盖要删除节点
    node = node->next;
    node->val = node->next->val;

    //删除多余的下一节点
    node->next = node->next->next;

    return head;
}
