//
// Created by Wanhui on 3/7/20.
//

#ifndef SWORDTOOFFER_MAXSLIDINGWINDOW_H
#define SWORDTOOFFER_MAXSLIDINGWINDOW_H

/*
 * 剑指offer 59-I 滑动窗口的最大值
 *
 * 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 *
 * 示例:
 *
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7]
 * 解释:
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 *
 * 提示：
 * 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 * */


#include <deque>
#include <vector>

// 实现单调队列 O(1)
class MonotonicQueue {
private:
    std::deque<int> data;
public:
    // 入队函数
    void push(int n) {
        // 如果队尾元素小于当前元素，
        // 则将队尾元素出队
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        // 入队当前元素，
        // 则队列中元素仍然保持递减
        data.push_back(n);
    }

    // 取队列最大元素，即队首
    int max() {
        return data.front();
    }

    // 弹出队首等于n的元素
    void pop(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }
};

class Solution59_1 {
public:
    /*
     * 方法1 单调队列 O(n)
     *
     * 窗口大小为k的滑动窗口，每次计算窗口内的最大值，可以使用单调队列的方法。
     * 单调队列保持队列中的值从大到小排列，将滑动窗口中的值入队后，
     * 队首元素即为该滑动窗口的最大值。而单调队列入队、出队和取最大值的平均时间为O(1),
     * 所以遍历整个数组，计算每个滑动窗口的最大值的时间复杂度为O(n)。
     * */
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k);

    /*
     * 原理同方法1 使用双端队列存储滑动窗口中数字的索引，同样实现单调队列的形式。
     *
     * 遍历数组时，将窗口逐渐右移：
     * 1. 当队列不为空时，如果当前队首索引不在窗口内时，将队首从队列中出队；
     * 2. 当队列不为空时，如果队尾索引对应的值小于当前值时，将队尾索引出队，
     *    直到找到索引对应值大于等于当前值，则将当前值对应的索引入队，保证双端队列是单调递减的；
     * 3. 因为双端队列索引对应的值是递减的，则队首索引对应的值即为该滑动窗口的最大值，返回该值。
     * */
    std::vector<int> maxSlidingWindow2(std::vector<int> &nums, int k);
};


#endif //SWORDTOOFFER_MAXSLIDINGWINDOW_H
