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


#include "DataStruct/SingleNodeList.h"

class Solution24 {
public:
    /*
     * 方法1 双指针迭代法
     *
     * 1->2->3->4->5->null
     * 1<-2<3   4->5->null
     *
     * 因为要反转链表，
     * 遍历节点visitnode只知道next节点，
     * 所以需要在visitnode前设置一个前节点prenode，
     * 每遍历一个节点，就将visitnode的next指向prenode，
     * 因为每次链表会断裂，需要将visitnode节点提前保存为nextnode，
     * 在将visitnode设为prenode，nextnode设为visitnode
     * 重复上述每一次遍历的操作，直到visitnode为空节点，
     * 在此前，最后一个节点已经赋给prenode，
     * 所以返回prenode为反转链表的头节点
     * */
    ListNode *reverseList(ListNode *head);


    /*
     * 方法2 递归法
     *
     * 1->2->3->4->5->null
     * 1->2->3->4<-5
     *
     * 递归法的难点有两个：
     * 1. 终止条件： 因为要反转链表，
     *    如果只是当前节点为null，则需要多一个节点，
     *    使当前节点为该节点的next的下一个节点，
     *    如果设为当前节点为null或下一节点为null，
     *    就能将当前节点设为next节点的next节点，
     *    达到反转的目的
     * 2. 头节点的返回：因为要返回头节点，
     *    所以递归函数返回的结果不能随递归变化，
     *    在递归函数内部，每次改变的是当前节点的指向
     *    (这里容易想到返回的结果也变化，那最终返回不了头节点)
     *
     * WARNing : 指针反转后，要设置当前节点的next节点为null，
     *           不然会发生循环，例如2个节点时
     * */
    ListNode *reverseList2(ListNode *head);
};


#endif //SWORDTOOFFER_REVERSELIST_H
