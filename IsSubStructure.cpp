//
// Created by Wanhui on 3/1/20.
//

#include "IsSubStructure.h"

bool Solution26::isSubStructure(BiTreeNode<int> *A, BiTreeNode<int> *B) {
    if (!A || !B) {
        return false;
    }

    return dfs(A, B) || isSubStructure(A->leftChild, B) || isSubStructure(A->rightChild, B);
}

bool Solution26::dfs(BiTreeNode<int> *A, BiTreeNode<int> *B) {
    if (!B) {
        return true;
    }

    if (!A) {
        return false;
    }

    return A->data == B->data && dfs(A->leftChild, B->leftChild) && dfs(A->rightChild, B->rightChild);
}
