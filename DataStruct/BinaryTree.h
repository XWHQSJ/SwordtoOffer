//
// Created by Wanhui on 2/27/20.
//

#ifndef SWORDTOOFFER_BINARYTREE_H
#define SWORDTOOFFER_BINARYTREE_H

template <typename T>
class BinaryTree{
public:
    // 构造函数
    BinaryTree() : root(nullptr){}

    // 指定结束标志的构造函数
    BinaryTree(T value) : RefValue(value), root(nullptr){}

    // 析构函数
    ~BinaryTree(){

    }


    // 二叉树的创建

    // 使用广义表创建二叉树，以"#"字符代表结束
    void CreateBinTree(){

    }

    void CreateBinTree_PreOrder(){

    }

    void CreateBinTreeBy_Pre_In(const char *pre, const char *in){

    }

    void Create_BinTreeBy_Post_In(const char *post, const char *in){

    }

private:
    // 根节点
    BinaryTree<T> *root;

    // 数据输入停止标志，
    // 需要构造函数初始化
    T RefValue;
};

#endif //SWORDTOOFFER_BINARYTREE_H
