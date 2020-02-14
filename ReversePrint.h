//
// Created by Wanhui on 2/14/20.
//

#ifndef SWORDTOOFFER_REVERSEPRINT_H
#define SWORDTOOFFER_REVERSEPRINT_H

/*
 * 剑指offer 06 从尾到头打印链表
 *
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 *
 * 示例 1：
 * 输入：head = [1,3,2]
 *
 * 输出：[2,3,1]
 *
 * 限制：
 * 0 <= 链表长度 <= 10000
 * */

#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution06 {
public:
    /*
     * 方法1 栈
     * */
    std::vector<int> reversePrint(ListNode *head);

    /*
     * 方法2 递归
     * */
    std::vector<int> reversePrint2(ListNode *head);
};


#endif //SWORDTOOFFER_REVERSEPRINT_H
