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



#include <vector>

class Solution59_1 {
public:
    /*
     * 方法1 单调双端队列
     *
     *
     * */
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k);

    /*
     * 方法2 动态规划
     *
     *
     * */
    std::vector<int> maxSlidingWindow2(std::vector<int> &nums, int k);
};


#endif //SWORDTOOFFER_MAXSLIDINGWINDOW_H
