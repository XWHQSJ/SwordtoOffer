//
// Created by Wanhui on 2/19/20.
//

#ifndef SWORDTOOFFER_DELETENODE_H
#define SWORDTOOFFER_DELETENODE_H

/*
 * 剑指offer 18　删除链表的节点
 *
 * 给定单向链表的头指针和一个要删除的节点的值，
 * 定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 *
 * 注意：此题对比原题有改动
 *
 * 示例 1:
 *
 * 输入: head = [4,5,1,9], val = 5
 * 输出: [4,1,9]
 * 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
 *
 * 示例 2:
 *
 * 输入: head = [4,5,1,9], val = 1
 * 输出: [4,5,9]
 * 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 *
 * 说明：
 * 题目保证链表中节点的值互不相同
 * 若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
 * */


#include "DataStruct/Node.h"

class Solution18 {
public:
    /*
     * 方法１　顺序查找法　O(n)
     *
     * 设置一个伪节点，将该节点指向头节点，
     * 目的是方便的返回头节点，
     * 当头节点的值与val相等，则删除头节点并返回头节点的下个节点
     * 当不相等，则从头节点的下一个节点head->next开始顺序查询链表，
     * 并将每个节点的值与val进行比较，
     * 如果相等则删除该节点，即head->next = head->next->next
     * */
    ListNode *deleteNode(ListNode *head, int val);

    /*
     * 方法2 覆盖节点法 O(1)
     *
     * Leetcode的题目与剑指offer原题的描述有差别
     * 原题的函数形参第二个值是ListNode*类型的
     * 当知道要删除的节点时，可以将该节点的后一个节点覆盖原节点，
     * 再将多余的后节点删除就等于删除了该节点
     * */
    ListNode* deleteNode(ListNode *head, ListNode *node);
};


#endif //SWORDTOOFFER_DELETENODE_H
