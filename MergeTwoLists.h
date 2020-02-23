//
// Created by Wanhui on 2/23/20.
//

#ifndef SWORDTOOFFER_MERGETWOLISTS_H
#define SWORDTOOFFER_MERGETWOLISTS_H

/*
 * 剑指offer 25 合并两个排序的链表
 *
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 *
 * 示例1：
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 *
 * 限制：
 * 0 <= 链表长度 <= 1000
 * */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution25 {
public:
    /*
     * 方法1 双指针迭代法
     * 设置头节点head(不动)和插入节点node(移动)，
     * 当两链表均不为空时，比较两链表头节点的值，
     * 值较小的节点插入到node节点的next节点，
     * 更新改变的链表的头节点，node节点移动，
     * 当迭代结束后，某一链表可能还有值未访问，
     * 将剩下有序的节点插入node的next节点即可，
     * 因为初始化node=head,所以返回head的next节点
     * */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

    /*
     * 方法2 递归法
     * 设置合并链表头节点head,比较两链表头节点的值，
     * 值较小的节点插入head节点，递归函数返回head节点的next节点的值
     * 返回合并链表的head节点
     * */
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2);
};


#endif //SWORDTOOFFER_MERGETWOLISTS_H
