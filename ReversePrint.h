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
     * 创建一个栈，将链表中的数据push到栈中，
     * 再将栈中数据pop到数组中，
     * 即完成了链表数据的反转
     * */
    std::vector<int> reversePrint(ListNode *head);

    /*
     * 方法2 递归
     * 使用递归访问链表的最后一个结点，
     * 再依次递归出栈，访问每个结点的值，
     * 存储到数组中完成反转
     * */
    std::vector<int> reversePrint2(ListNode *head);

    /*
     * 递归反转函数
     *  WARNing : std::vector<int>& vec
     * 一定要设置为引用，
     * &引用使传入的数组与函数内使用的数组指向相同的地址
     * 因此函数内数组的值改变，函数外的数组值也会改变
     */
    static void reverse(ListNode* head, std::vector<int>& vec);
};


#endif //SWORDTOOFFER_REVERSEPRINT_H
