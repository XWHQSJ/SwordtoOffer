//
// Created by Wanhui on 2/20/20.
//

#ifndef SWORDTOOFFER_GETKTHFROMEND_H
#define SWORDTOOFFER_GETKTHFROMEND_H

/*
 * 剑指offer 22 链表中倒数第k个节点
 *
 * 输入一个链表，输出该链表中倒数第k个节点。
 * 为了符合大多数人的习惯，本题从1开始计数，
 * 即链表的尾节点是倒数第1个节点。
 * 例如，一个链表有6个节点，从头节点开始，
 * 它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 k = 2.
 * 返回链表 4->5.
 * */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution22 {
public:
    /*
     * 方法1 快慢指针法
     * 设置两个指针都指向头节点
     * 快指针先移动到第k个节点，
     * 剩下n-k个节点未访问
     * 之后快慢指针一起移动，
     * 当快指针指向最后一个节点，
     * 慢指针访问过n-k个节点，
     * 即慢指针指向倒数第k个节点
     * */
    ListNode *getKthFromEnd(ListNode *head, int k);

    // 方法1效率高些的实现方式
    ListNode *getKthFromEnd_2(ListNode *head, int k);


    /*
     * 方法2 递归法
     * 用递归访问链表的最后一个节点，
     * 再依次递归出栈，访问每个节点并将k减1，
     * 当k等于0时，就找到了倒数第k个节点。
     *
     * WARNing1 : 当链表很长时，会导致递归栈过深，
     * 栈溢出，运行时间超时的问题
     *
     *  WARNing2 : int &k 的使用
     * 设置为引用，每次递归k的值才能改变
     * */
    ListNode *getKthFromEnd2(ListNode *head, int &k);

};


#endif //SWORDTOOFFER_GETKTHFROMEND_H
