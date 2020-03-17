//
// Created by Wanhui on 3/17/20.
//

#ifndef SWORDTOOFFER_CODEC_H
#define SWORDTOOFFER_CODEC_H

/*
 * 剑指offer 37 序列化二叉树
 *
 * 请实现两个函数，分别用来序列化和反序列化二叉树。
 *
 * 示例:
 *
 * 你可以将以下二叉树：
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 *
 * 序列化为 "[1,2,3,null,null,4,5]"
 * */


#include <DataStruct/BiTreeNode.h>
#include <string>

class Solution37 {
public:
    // Encodes a tree to a single string.
    std::string serialize(BiTreeNode* root);

    // Decodes your encoded data to tree.
    BiTreeNode* deserialize(std::string data);
};


#endif //SWORDTOOFFER_CODEC_H
