//
// Created by Wanhui on 3/1/20.
//

#include "IsSubStructure.h"

bool Solution26::isSubStructure(BiTreeNode<int> *A, BiTreeNode<int> *B) {
    // 空树不是任意一个树的子结构
    if (!A || !B) {
        return false;
    }

    // 不断遍历树A，直到找到与B根节点相等的点
    return dfs(A, B) || isSubStructure(A->leftChild, B) || isSubStructure(A->rightChild, B);
}

bool Solution26::dfs(BiTreeNode<int> *A, BiTreeNode<int> *B) {
    // B为空表示B已经遍历结束，
    // 返回true
    if (!B) {
        return true;
    }

    // B不为空,A为空时，
    // 表示B不是A的子结构
    if (!A) {
        return false;
    }

    // 如果A中不存在B的根节点
    // 返回false
    if(A->data != B->data){
        return false;
    }

    // 如果A中存在B的根节点，则继续遍历左右子树是否也完全相同
    // 完全遍历过树B后，都符合则返回true
    return  dfs(A->leftChild, B->leftChild) && dfs(A->rightChild, B->rightChild);
}
