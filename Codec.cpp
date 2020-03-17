//
// Created by Wanhui on 3/17/20.
//

#include <queue>
#include <utility>
#include "Codec.h"

std::string Solution37::serialize(BiTreeNode *root) {
    std::string str;
    // 层序遍历存储二叉树节点的队列
    std::queue<BiTreeNode *> que;
    // 压入根节点
    que.push(root);

    while (!que.empty()) {
        // 取队列头节点
        BiTreeNode *node = que.front();

        // 如果头节点为空，则字符串添加 null,
        if (node == nullptr) {
            str += "null,";
        } else {
            // 头节点不为空，字符串添加该节点的 值+,
            str += std::to_string(node->val) + ",";
            // 将该头节点的左右子节点压入队列
            que.push(node->left);
            que.push(node->right);
        }
        // 当前节点出队
        que.pop();
    }

    return str;
}


BiTreeNode *Solution37::deserialize(std::string data) {
    // 使用数组存储赋值的节点
    std::vector<BiTreeNode *> list;

    // l指向节点字符，r指向字符 ',' 和处理字符串 "null"
    // r因为是作为分割处理的，所以一直在l的右边
    int l = 0, r = 0;

    // 对数据字符串进行遍历
    while (l < data.size()) {
        // l与r从同一位置开始
        r = l;

        // 使r始终指向l右边的字符 ',' 位置
        while (data[r] != ',') {
            r++;
        }

        // 当l指向字符 'n' ，表示当前字符串为 "null"
        if (data[l] == 'n') {
            // 跨过字符串 "null" ，l直接指向下一个节点的字符串
            l = r + 1;
            // 因为是字符串 "null" ，所以将空指针nullptr存入节点数组中
            list.push_back(nullptr);
            // 重新将l与r放在当前l指向的位置，开始新一轮遍历
            continue;
        }

        // val表示节点的值
        int val = 0;
        // sign对节点的值做正负处理
        int sign = 1;

        // 当前l遍历的字符为 '-' ，
        // 表示该节点的值为负数
        if (l < r && data[l] == '-') {
            sign = -1;
            // l指向负号后面的数字
            l++;
        }

        // 对多位数进行处理，例如 -212
        for (int i = l; i < r; i++) {
            // 将字符串数字转化为整数
            val = val * 10 + data[i] - '0';
        }

        // 对节点的值赋正负号
        val *= sign;
        // l指向下一个节点
        l = r + 1;

        // 将获得的节点的值赋值给创建的节点
        auto newNode = new BiTreeNode(val);
        // 将该节点存入节点存储数组中
        list.push_back(newNode);
    }

    // 取节点存储数组的头节点，即二叉树的根节点
    auto listNode = list[0];
    // 当前节点指针
    auto curNode = listNode;

    // 遍历节点存储数组
    // j表示当前的根节点，遇到字符串"null"就递进
    // i表示当前的左右子节点，相邻两个构成一个根节点的左右子节点
    for (int i = 1, j = 1; i < list.size() && j < list.size(); j++) {
        // 如果当前节点为nullptr
        if (!curNode) {
            // 则将当前节点回溯为nullptr的根节点
            curNode = list[j];
            // 继续下一轮判断
            continue;
        }

        // 链接根节点的左节点
        curNode->left = list[i];
        // 链接根节点的右节点
        curNode->right = list[i + 1];
        // 当前节点为根节点
        curNode = list[j];

        // 左右孩子节点为两个
        i += 2;
    }

    return listNode;
}


std::string Solution37::serialize2(BiTreeNode *root) {
    return dfsSerialize(root, "");
}

std::string Solution37::dfsSerialize(BiTreeNode *root, std::string str) {
    // 如果根节点为空，则字符串添加 null,
    if (root == nullptr) {
        str += "null,";
    } else {
        // 如果根节点不为空，则字符串添加该节点的 值+,
        str += std::to_string(root->val) + ",";
        // dfs深度遍历该节点的左右子节点
        dfsSerialize(root->left, str);
        dfsSerialize(root->right, str);
    }

    return str;
}

BiTreeNode *Solution37::deserialize2(std::string data) {
    int l = 0;
    return dfsDeserialize(std::move(data), l);
}

BiTreeNode *Solution37::dfsDeserialize(std::string data, int &l) {
    // 递归结束，返回空指针
    if (l == data.size()) {
        return nullptr;
    }

    // r为处理字符 ',' 和字符串 "null"
    // r因为是作为分割处理的，所以一直在l的右边
    int r = l;
    // r指向字符 ','
    while (data[r] != ',') {
        r++;
    }
    // 如果l指向字符 'n' ,表示该字符串为 "null"
    // 此时r指向字符串 "null" 后面的 ','
    if (data[l] == 'n') {
        // l指向r后面的字符，跨过字符串 "null"
        l = r + 1;

        // 因为指向的是字符串 "null" ，所以返回的是空指针nullptr
        return nullptr;
    }

    // val表示节点的值
    int val = 0;
    // sign对节点的值做正负处理
    int sign = 1;

    // 当前l遍历的字符为 '-' ，
    // 表示该节点的值为负数
    if (l < r && data[l] == '-') {
        sign = -1;
        // l指向负号后面的数字
        l++;
    }

    // 对多位数进行处理，例如 -212
    for (int i = l; i < r; i++) {
        // 将字符串数字转化为整数
        val = val * 10 + data[i] - '0';
    }

    // 对节点的值赋正负号
    val *= sign;
    // l指向下一个节点
    l = r + 1;

    // 将获得的节点的值赋值给创建的节点
    auto root = new BiTreeNode(val);
    // 对该节点的左右子节点进行递归处理
    root->left = dfsDeserialize(data, l);
    root->right = dfsDeserialize(data, l);

    return root;
}


