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
