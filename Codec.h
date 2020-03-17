//
// Created by Wanhui on 3/17/20.
//

#ifndef SWORDTOOFFER_CODEC_H
#define SWORDTOOFFER_CODEC_H

/*
 * 剑指offer 37 序列化二叉树
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，
 * 进而可以将转换后的数据存储在一个文件或者内存中，
 * 同时也可以通过网络传输到另一个计算机环境，
 * 采取相反方式重构得到原数据。
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
 *
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，
 * 你的序列化和反序列化算法应该是无状态的。
 * */


#include <DataStruct/BiTreeNode.h>
#include <string>
#include <list>


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
class Solution37 {
public:

    /*
     * 方法1 层序遍历
     *
     * 序列化：
     * 使用层序遍历的方式对二叉树进行序列化
     *
     * 反序列化：
     * 先将数据字符串按照二叉树节点的形式，将字符串转换为相应的节点，存储在数组中；
     * 再对数组中按层序遍历顺序存储的节点，以根节点->左子节点->右子节点的方式进行链接。
     * */
    // Encodes a tree to a single string.
    std::string serialize(BiTreeNode *root);

    // Decodes your encoded data to tree.
    BiTreeNode *deserialize(std::string data);


    /*
     * 方法2 前序遍历 + DFS
     *
     * 序列化：
     * 按照前序遍历的方式对二叉树进行递归序列化
     *
     * 反序列化：
     * 先将数据字符串中的二叉树节点转换为节点模式，并将第一个值赋值给根节点，
     * 再递归处理后面的每个字符串，并相应的赋值为根节点左右子节点。
     * */
    // Encodes a tree to a single string.
    std::string serialize2(BiTreeNode *root);

    std::string dfsSerialize(BiTreeNode *root, std::string str);

    // Decodes your encoded data to tree.
    BiTreeNode *deserialize2(std::string data);

    BiTreeNode *dfsDeserialize(std::string data, int &u);
};


#endif //SWORDTOOFFER_CODEC_H
