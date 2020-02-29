//
// Created by Wanhui on 2/29/20.
//

#include <cassert>
#include <climits>
#include "MaxSubArray.h"

int Solution42::maxSubArray(std::vector<int> &nums) {
    assert(!nums.empty());

    int resSum = INT_MIN;
    int curSum = 0;

    // 遍历数组
    for (int i = 0; i < nums.size(); i++) {
        // 当sum小于0时，就从下一个数重新开始
        // 同时更新每次叠加的最大值
        if (curSum <= 0) {
            curSum = nums[i];
        } else {
            // 和大于0时
            curSum += nums[i];
        }

        // 不断更新子串的最大值
        if (curSum > resSum) {
            resSum = curSum;
        }
    }

    return resSum;
}


int Solution42::maxSubArray2(std::vector<int> &nums) {
    assert(!nums.empty());

    return helper(nums, 0, nums.size() - 1);
}

int Solution42::helper(std::vector<int> &nums, int left, int right) {
    // 分解到一个值时返回该值
    if (left == right) {
        return nums[left];
    }

    // 求中点值
    int mid = left + (right - left) / 2;

    // 中点左边的最大值
    int leftSum = helper(nums, left, mid);
    // 中点右边的最大值
    int rightSum = helper(nums, mid + 1, right);
    // 横跨中点的最大值
    int croSum = crossSum(nums, left, right, mid);

    // 返回以上三种情况中的最大值
    return std::max(std::max(leftSum, rightSum), croSum);
}

int Solution42::crossSum(std::vector<int> &nums, int left, int right, int mid) {
    // 分解到一个值时返回该值
    if (left == right) {
        return nums[left];
    }

    // 贪心法求左边的最大值
    int leftSubsum = INT_MIN;
    int curSum = 0;
    for (int i = mid; i > left - 1; i--) {
        curSum += nums[i];
        leftSubsum = std::max(leftSubsum, curSum);
    }

    // 贪心法求右边的最大值
    int rightSubsum = INT_MIN;
    curSum = 0;
    for (int i = mid + 1; i < right + 1; i++) {
        curSum += nums[i];
        rightSubsum = std::max(rightSubsum, curSum);
    }

    return leftSubsum + rightSubsum;
}

int Solution42::maxSubArray3(std::vector<int> &nums) {
    assert(!nums.empty());

    int n = nums.size();
    int maxSum = nums[0];

    // 如果当前值小于0，
    // 重新开始(全局最大值更新)
    for (int i = 1; i < n; i++) {
        // 更新当前的最大值
        if (nums[i - 1] > 0) {
            nums[i] += nums[i - 1];
        }
        // 更新全局的最大值
        maxSum = std::max(nums[i], maxSum);
    }

    return maxSum;
}

