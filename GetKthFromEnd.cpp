//
// Created by Wanhui on 2/20/20.
//

#include "GetKthFromEnd.h"

ListNode *Solution22::getKthFromEnd(ListNode *head, int k) {
    if (head == nullptr || k == 0) {
        return nullptr;
    }

    ListNode *pa = head;
    ListNode *pb = head;

    for (int i = 1; i < k; i++) {
        if (pa->next != nullptr) {
            pa = pa->next;
        } else {
            return nullptr;
        }
    }

    while (pa->next != nullptr) {
        pa = pa->next;
        pb = pb->next;
    }

    return pb;
}

ListNode *Solution22::getKthFromEnd_2(ListNode *head, int k) {
    if(head == nullptr || k == 0){
        return nullptr;
    }

    ListNode *pa = head;
    ListNode *pb = head;

    // 计数访问的节点数
    // 只有pa访问到第k个时，pa才开始移动
    int count = 0;
    while (pa != nullptr){
        if(count >= k){
            pb = pb->next;
        }

        pa = pa->next;
        count++;
    }

    // k可能比链表的长度要大
    if(count < k){
        return nullptr;
    }

    return pb;
}

ListNode *Solution22::getKthFromEnd2(ListNode *head, int &k) {
    if(head == nullptr || k == 0){
        return nullptr;
    }

    ListNode* res = getKthFromEnd2(head->next, k);
    k--;

    if(k == 0){
        return head;
    }

    return  res;
}
