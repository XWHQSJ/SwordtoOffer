//
// Created by Wanhui on 2/25/20.
//

#ifndef SWORDTOOFFER_COPYRANDOMLIST_H
#define SWORDTOOFFER_COPYRANDOMLIST_H


/*
 * 剑指offer 35 复杂链表的复制
 *
 * 请实现 copyRandomList 函数，复制一个复杂链表。
 * 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
 * 还有一个 random 指针指向链表中的任意节点或者 null。
 *
 * 示例 1：
 *
 * 图 复杂链表的复制1.png
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 * 示例 2：
 *
 * 图 复杂链表的复制2.png
 *
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 * 示例 3：
 *
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 * 示例 4：
 *
 * 图 复杂链表的复制3.png
 *
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 *
 * 提示：
 * -10000 <= BiNode.val <= 10000
 * BiNode.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 * */


#include "DataStruct/Node.h"

class Solution35 {
public:
    /*
     * 方法1 分解法
     *
     * A->A'->B->B'->C->C'->D->D'->E->E'
     * |_____R|_______|R    |      |R
     *        |_____________|______|
     *        |_____________|
     *
     * 1. 根据原链表的value和next对原链表进行复制，
     *    复制的节点在原节点之后，此步未处理random指针
     * 2. 遍历链表，复制每个节点的random指针
     * 3. 将复制后的链表拆分为原链表和复制链表。
     * */
    Node *copyRandomList(Node *head);

    /*
     * 复制原链表的节点，
     * 复制节点接在原节点之后
     * */
    void copyNodes(Node *head);

    /*
     * 遍历链表，复制random指针
     * */
    void connectRandomNode(Node *head);

    /*
     * 拆分复制链表
     * */
    Node *splitCopyNodeList(Node *head);


    /*
     * 方法2 哈希表法
     *
     * 使用map<Node*,Node*>建立哈希表，
     * 将原节点与复制节点对应起来，
     *
     * 1. 建立 map 。map<Node *, Node *> visited；
     * 2. NULL 指针加入 map ，当指针为 NULL 时能对应visited[NULL] = NULL；
     * 3. 使用标准链表遍历方式： while (pNode != NULL) pNode = pNode->next；
     * 4. new 新的 Node ，并保存在 map 中；
     * 5. 指针回到 head ，再遍历一遍链表，用来复制 Node 中的数据；
     * 6. 需要复制的有：val, random, next；
     * 7. 返回新数据的 head 指针，没错，就是 visited[head] 。
     * */
    Node *copyRandomList2(Node *head);


    /*
     * 方法3 回溯法
     *
     * 回溯算法的第一想法是将链表想象成一张图或树，如图1。
     * 链表中每个节点都有 2 个指针（图中的边）。
     * 因为随机指针给图结构添加了随机性，
     * 所以我们可能会访问相同的节点多次，这样就形成了环。
     *
     * 图1 复杂链表的复制回溯法1.png
     * 图2 复杂链表的复制回溯法2.png
     *
     * 1. 从头指针开始遍历整个图，如图2；
     * 2. 当遍历到某个节点时，如果已经有了当前节点的拷贝，则无需重复拷贝；
     * 3. 如果没有拷贝当前节点，则创造新节点，并放入map访问字典中；
     * 4. 进行回溯调用：顺着next指针和顺着random指针
     * */
    Node *copyRandomList3(Node *head);
};


#endif //SWORDTOOFFER_COPYRANDOMLIST_H
