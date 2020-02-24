//
// Created by Wanhui on 2/23/20.
//

#include "GetIntersectionNode.h"

ListNode *Solution52::getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 两链表为空的情况
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    unsigned int alen = getListLength(headA);
    unsigned int blen = getListLength(headB);
    int distance = alen - blen;

    ListNode *longnode = headA;
    ListNode *shortnode = headB;

    // 确定长链表，并计算长链表与短链表间的距离
    if (blen > alen) {
        longnode = headB;
        shortnode = headA;
        distance = blen - alen;
    }

    // 长链表指针先遍历distance个节点，
    // 保证两链表接下来遍历长度相等
    for (int i = 0; i < distance; i++) {
        longnode = longnode->next;
    }

    // 普通遍历，如果指针相等或遍历结束即停止
    while (longnode != nullptr && shortnode != nullptr && longnode != shortnode) {
        longnode = longnode->next;
        shortnode = shortnode->next;
    }

    return longnode;
}

unsigned int Solution52::getListLength(ListNode *head) {
    unsigned int length = 0;
    ListNode *node = head;
    // 计算链表的长度
    while (node != nullptr) {
        ++length;
        node = node->next;
    }

    return length;
}

ListNode *Solution52::getIntersectionNode2(ListNode *headA, ListNode *headB) {
    // 两链表为空的情况
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    ListNode *pa = headA, *pb = headB;

    // 如果pa与pb不相等就继续遍历
    // 指针循环遍历必然出结果
    // 如果两指针等长且不相交，则第一轮均遍历到pa==pb==nullptr
    while (pa != pb) {
        // 当pa遍历到链表A的末尾，就转向链表B继续遍历
        pa = (pa == nullptr ? headB : pa->next);
        // 当pb遍历到链表B的末尾，就转向链表A继续遍历
        pb = (pb == nullptr ? headA : pb->next);
    }

    return pa;
}
