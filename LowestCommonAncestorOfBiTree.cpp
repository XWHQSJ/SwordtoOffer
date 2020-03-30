//
// Created by Wanhui on 3/28/20.
//

#include <stack>
#include <unordered_set>
#include <unordered_map>
#include "LowestCommonAncestorOfBiTree.h"

BiTreeNode *Solution68_2::lowestCommonAncestor(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }

    // 如果该节点为节点p或节点q即返回
    if (root == p || root == q) {
        return root;
    }

    // 遍历左子树
    BiTreeNode *left = lowestCommonAncestor(root->left, p, q);
    // 遍历右子树
    BiTreeNode *right = lowestCommonAncestor(root->right, p, q);

    // 如果遍历到左子树为空，则遍历右子树
    if (left == nullptr) {
        return right;
    }

    // 如果遍历到右子树为空，则遍历左子树
    if (right == nullptr) {
        return left;
    }

    // 如果左右子树都不为空，则左右子树存在节点p,q
    // 当前节点即为节点p,q的最近公共祖先
    return root;
}

BiTreeNode *Solution68_2::lowestCommonAncestor2(BiTreeNode *root, BiTreeNode *p, BiTreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }

    // 遍历树的栈
    std::stack<BiTreeNode *> stk;
    // 存储祖先节点的哈希表
    std::unordered_map<BiTreeNode *, BiTreeNode *> parentsMap;

    // 存入根节点，对应的祖先节点为nullptr
    parentsMap[root] = nullptr;
    // 遍历根节点
    stk.push(root);

    // 当未找到节点p或q时不断遍历
    while (parentsMap.find(p) == parentsMap.end() || parentsMap.find(q) == parentsMap.end()) {
        // 取树栈的栈顶节点，
        // 并弹出栈顶节点
        BiTreeNode *node = stk.top();
        stk.pop();

        // 如果栈顶节点的左节点不为空
        if (node->left != nullptr) {
            // 将该节点为左节点的父节点，
            // 将该父指针存入哈希表中
            parentsMap[node->left] = node;

            // 将左节点入栈
            stk.push(node->left);
        }

        // 与左节点同理
        if (node->right != nullptr) {
            parentsMap[node->right] = node;
            stk.push(node->right);
        }
    }

    // 定义节点p或q的祖先节点哈希集合
    std::unordered_set<BiTreeNode *> ancestorsSet;
    while (p != nullptr) {
        // 插入祖先节点
        ancestorsSet.insert(p);

        // 迭代插入
        p = parentsMap[p];
    }

    // 遍历q的祖先节点，并与p的祖先集合中的节点进行比较
    while (ancestorsSet.find(q) == ancestorsSet.end()) {
        // 从下向上地迭代比较
        q = parentsMap[q];
    }

    // 返回找到的第一个公共祖先
    return q;
}
