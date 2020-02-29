//
// Created by Wanhui on 2/23/20.
//

#ifndef SWORDTOOFFER_GETINTERSECTIONNODE_H
#define SWORDTOOFFER_GETINTERSECTIONNODE_H

/*
 * 剑指offer 两个链表的第一个公共节点
 *
 * 输入两个链表，找出它们的第一个公共节点。
 *
 * 如下面的两个链表：
 * 图 -- 两个链表的第一个公共节点1.png
 * 在节点 c1 开始相交。
 *
 * 示例 1：
 *
 * 图 -- 两个链表的第一个公共节点2.png
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 * 输出：Reference of the node with value = 8
 * 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
 * 从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
 * 在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 *
 * 示例 2：
 *
 * 两个链表的第一个公共节点3.png
 * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 * 输出：Reference of the node with value = 2
 * 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。
 * 从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
 * 在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 *
 * 示例 3：
 *
 * 两个链表的第一个公共节点4.png
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：null
 * 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
 * 由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 * 解释：这两个链表不相交，因此返回 null。
 *
 * 注意：
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 * */


#include "DataStruct/Node.h"


class Solution52 {
public:
    /*
     * 本题思路有：
     * 1. 暴力解决
     *    直接对两链表的数据进行逐一比较
     *    时间复杂度O(mn)，空间复杂度O(1)
     *
     * 2. 空间换时间
     *    使用哈希表、栈或数组存储其中一个链表，
     *    再跟另一链表逐一比较
     *    时间复杂度O(m+n)，空间复杂度O(n)或O(m)
     *
     * 3. 双指针
     *    因为如果两链表相交，那么从相交点开始，两链表相同，
     *    倒过来思考，如果从尾部向前遍历，指向两链表的指针，
     *    在链表的步调是一致的，那么只要终止条件一致就能在一轮循环中结束，
     *    所以只要找到两链表的长度距离，时间复杂度就是O(n)
     * */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

    unsigned int getListLength(ListNode *head);

    /*
     * 双指针
     * 找到两链表的差异意图是让遍历时两链表等长，
     * 让两链表都加长为同一长度也是一个解决思路，
     * 巧妙的是，让指向两链表的指针都遍历(m+n)长度，
     * 则必然返回两链表是否有公共节点的结果，
     * 如果不相交返回null，相交则返回指针相等时指向的节点
     * */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB);
};


#endif //SWORDTOOFFER_GETINTERSECTIONNODE_H
