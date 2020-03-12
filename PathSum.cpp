//
// Created by Wanhui on 3/12/20.
//

#include "PathSum.h"

std::vector<std::vector<int>> Solution34::pathSum(BiTreeNode *root, int sum) {
    if (root == nullptr) {
        return {};
    }

    // 存储路径节点的数组
    std::vector<int> path;
    // 当前路径和
    int curSum = 0;

    findPath(root, sum, path, curSum);

    return ans;
}

void Solution34::findPath(BiTreeNode *root, int sum, std::vector<int> &path, int curSum) {
    // 将当前节点值累加到当前路径和
    curSum += root->val;
    // 将当前节点压入存储路径节点数组中
    path.push_back(root->val);

    // 判断当前节点是否为叶节点
    bool isLeaf = (root->left == nullptr) && (root->right == nullptr);

    // 如果当前节点是叶节点，且当前路径和满足条件
    if (curSum == sum && isLeaf) {
        // 将该路径上的节点值返回
        for (int &p : path) {
            pathAns.push_back(p);
        }
        ans.push_back(pathAns);
        // 对当前路径存储数组置空
        pathAns = {};
    }

    // 如果当前节点是非叶节点，判断该节点左子节点是否为空，
    // 如果不为空，则对左子树进行递归遍历
    if (root->left != nullptr) {
        findPath(root->left, sum, path, curSum);
    }

    // 如果当前节点是非叶节点，判断该节点右子节点是否为空，
    // 如果不为空，则对右子树进行递归遍历
    if (root->right != nullptr) {
        findPath(root->right, sum, path, curSum);
    }

    path.pop_back();
}


