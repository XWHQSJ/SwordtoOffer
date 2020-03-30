//
// Created by Wanhui on 3/28/20.
//

#ifndef SWORDTOOFFER_LOWESTCOMMONANCESTOROFBITREE_H
#define SWORDTOOFFER_LOWESTCOMMONANCESTOROFBITREE_H

/*
 * 剑指offer 68-II 二叉树的最近公共祖先
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
 * 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 * 见图：
 *
 * 示例 1:
 *
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 *
 * 示例 2:
 *
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 *
 * 说明:
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 * */


#include <DataStruct/BiTreeNode.h>

class Solution68_2 {
public:
    /*
     * 递归遍历 O(n)
     *
     * 递归遍历的目的是在子树中是否能够找到节点p或q，如果找到则返回p或q，
     * 如果未找到，则从其他子树中继续遍历，直到找到节点p或q，再返回最低公共祖先节点。
     * 1. 如果当前节点等于nullptr则直接返回nullptr；
     * 2. 如果当前节点为p或q，则当前子树存在节点p或q，返回当前节点；
     * 3. 如果当前节点不是p或q，则递归遍历左右子树：
     *    1) 如果遍历到左子树为空，仍然没找到p或q，则回溯到右子树继续遍历；
     *    2) 如果遍历到右子树为空，仍然没找到p或q，则回溯到左子树继续遍历；
     *    3) 如果左右子树都非空，即左右子树找到了节点p或q，则左右子树的当前节点是节点p和q的最近公共祖先。
     * */
    BiTreeNode *lowestCommonAncestor(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q);

    /*
     * 使用父指针迭代 O(n)
     *
     * 本方法不局限于二叉树或二叉搜索树，可以直接使用于树的最近公共祖先节点的查找中。
     *
     * 如果每个节点都有父指针，则可以从节点p或q返回以获取它们的祖先。
     * 在遍历的过程中，得到的第一个公共节点即为最近公共祖先节点。
     * 要实现每个节点都有父指针，可以在遍历二叉树时将父指针保存到字典中。
     * 1. 从根节点开始遍树；
     * 2. 在找到节点p或q前，将父指针存储到紫殿中；
     * 3. 当找到节点p或q时，可以使用父亲字典获得p或q的所有祖先，并添加到一个祖先集合中；
     * 4. 同时向上遍历p和q的祖先集合中的节点，如果找到第一个它们的祖先相同，则该节点是p和q的最近公共祖先。
     *
     * 代码实现上:
     * 1> 使用unordered_map哈希表存储父指针;
     * 2> 使用stack栈实现二叉树的遍历；
     * 3> 使用unorder_set哈希集合存储节点p或q的祖先节点。
     * */
    BiTreeNode *lowestCommonAncestor2(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q);
};


#endif //SWORDTOOFFER_LOWESTCOMMONANCESTOROFBITREE_H
