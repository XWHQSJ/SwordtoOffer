//
// Created by Wanhui on 3/27/20.
//

#include <algorithm>
#include "IsStraight.h"

bool Solution61::isStraight(std::vector<int> &nums) {
    if (nums.empty() || nums.size() < 5) {
        return false;
    }

    // 将数组排序为升序
    std::sort(nums.begin(), nums.end());

    // 计数0的个数
    int isZero = 0;
    for (int n : nums) {
        if (n == 0) {
            isZero++;
        }
    }

    // 数组在缺少的数
    int isGap = 0;
    // 左边的数，从第一个不为0的数开始
    int left = isZero;
    // 右边的数
    int right = left + 1;
    while (right < nums.size()) {

        // 如果两个数相等，必然不是顺子
        if (nums[left] == nums[right]) {
            return false;
        }

        // 计算数组中缺少的数
        isGap += nums[right] - nums[left] - 1;

        left++;
        right++;
    }

    // 比较缺少的数与0的个数
    return isGap <= isZero;
}
