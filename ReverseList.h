//
// Created by Wanhui on 2/23/20.
//

#ifndef SWORDTOOFFER_REVERSELIST_H
#define SWORDTOOFFER_REVERSELIST_H

/*
 * 剑指offer 24 反转链表
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 *
 * 限制：
 * 0 <= 节点个数 <= 5000
 * */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution24 {
public:
    /*
     *
     *
     * */
    ListNode *reverseList(ListNode *head);
};


#endif //SWORDTOOFFER_REVERSELIST_H
