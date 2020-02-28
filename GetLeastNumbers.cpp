//
// Created by Wanhui on 2/28/20.
//

#include <algorithm>
#include <queue>
#include "GetLeastNumbers.h"

// sort()函数
std::vector<int> Solution40::getLeastNumbers(std::vector<int> &arr, int k) {
    std::sort(arr.begin(), arr.end());

    std::vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(arr[i]);
    }

    return res;
}

// 大顶堆法
std::vector<int> Solution40::getLeastNumbers2(std::vector<int> &arr, int k) {
    // 定义大顶堆
    std::priority_queue<int, std::vector<int>, std::less<>> que;

    // 遍历数组数值
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        // 将数组构建为大顶堆
        que.push(*it);

        // 从大顶堆堆顶弹出k小数之外的较大的数
        if (que.size() > k) {
            que.pop();
        }
    }

    std::vector<int> res;

    // 遍历大顶堆，返回k个节点的值
    while (!que.empty()) {
        res.push_back(que.top());
        que.pop();
    }

    return res;
}
