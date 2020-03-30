//
// Created by Wanhui on 3/7/20.
//

#include "MaxSlidingWindow.h"

std::vector<int> Solution59_1::maxSlidingWindow(std::vector<int> &nums, int k) {
    if (nums.empty()) {
        return {};
    }

    // 定义存储滑动窗口内值的单调队列
    MonotonicQueue window;

    std::vector<int> ans;

    // 遍历数组中的数
    for (int i = 0; i < nums.size(); i++) {
        // 将该滑动窗口内的前k-1个数压入队列
        // 队列始终保持从大到小递减
        if (i < k - 1) {
            window.push(nums[i]);
        } else {
            // 窗口向前滑动，压入第k个数
            window.push(nums[i]);
            // 取队列中的最大数为该滑动窗口最大值
            ans.push_back(window.max());
            // 因为窗口向右滑动，弹出窗口的第一个数
            window.pop(nums[i - k + 1]);
        }
    }

    return ans;
}

std::vector<int> Solution59_1::maxSlidingWindow2(std::vector<int> &nums, int k) {
    if (nums.empty()) {
        return {};
    }

    // 定义双端队列
    std::deque<int> winDeq;

    // 将第一个窗口的值对应的索引按照单调队列入队
    for (int i = 0; i < k; i++) {
        while (!winDeq.empty() && nums[i] > nums[winDeq.back()]) {
            winDeq.pop_back();
        }
        winDeq.push_back(i);
    }

    std::vector<int> ans;
    // 将第一个窗口的最大值存入结果数组中
    ans.push_back(nums[winDeq.front()]);

    // 此后将滑动窗口右移，从第k个数开始
    for (int i = k; i < nums.size(); i++) {
        // 如果队首索引不在窗口内时，
        if (i - winDeq.front() == k) {
            // 则将队首出队
            winDeq.pop_front();
        }
        // 将下一个窗口的数对应的索引入队
        while (!winDeq.empty() && nums[i] > nums[winDeq.back()]) {
            winDeq.pop_back();
        }
        winDeq.push_back(i);

        // 每次返回队列的队首
        ans.push_back(nums[winDeq.front()]);
    }
    return ans;
}

