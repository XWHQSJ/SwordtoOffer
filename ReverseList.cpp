//
// Created by Wanhui on 2/23/20.
//

#include "ReverseList.h"

ListNode *Solution24::reverseList(ListNode *head) {
    // 空链表
    if (head == nullptr) {
        return head;
    }

    // 遍历链表指针
    ListNode *visitnode = head;
    // 指向遍历指针前一节点的指针
    ListNode *prenode = nullptr;

    while (visitnode != nullptr) {
        // 每遍历一个节点，将该节点的next节点保存
        ListNode *nextnode = visitnode->next;

        // 每遍历一个节点后，对节点进行反转
        // 将该节点的next指针指向prenode节点
        // 此时遍历节点与nextnode之间断裂
        visitnode->next = prenode;

        // prenode节点指向遍历节点
        prenode = visitnode;

        // 将保存好的nextnode节点交给遍历节点继续遍历
        visitnode = nextnode;
    }

    // 最后prenode=visitnode，
    // 即prenode为反转链表的头节点
    // 而最后visitnode为空节点
    return prenode;
}


ListNode *Solution24::reverseList2(ListNode *head) {
    // 递归终止条件是当前为空，或下一节点为空
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // node为原链表的最后一个节点，
    // 也即反转链表的头节点
    ListNode *node = reverseList2(head->next);

    // node为最后一个节点，
    // head此时为倒数第二个节点，
    // 反转即是将head节点设为head->next的next节点
    head->next->next = head;

    // 防止链表循环，例如2个节点时，
    // 需要将head->next设为空
    head->next = nullptr;

    // 每层递归都返回node节点
    return node;
}



















