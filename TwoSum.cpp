//
// Created by Wanhui on 3/6/20.
//

#include <unordered_map>
#include "TwoSum.h"

std::vector<int> Solution57::twoSum(std::vector<int> &nums, int target) {
    std::vector<int> ans = {0, 0};

    // 双侧指针，i指向数组左侧，j指向数组右侧
    int i = 0, j = nums.size() - 1;

    // 因为是求两个数的和，
    // 那么数组中大于target的数也就没必要遍历了
    while (nums[j] >= target) {
        j--;
    }

    // 当i比j小的时候，
    // 如果和大于target则j向左侧移动，
    // 如果和小于target则i向右侧移动
    while (i < j) {
        // i和j指向的数和等于target
        if (nums[i] + nums[j] == target) {
            ans[0] = nums[i];
            ans[1] = nums[j];
            break;
        } else if (nums[i] + nums[j] > target) {
            j--;
        } else {
            i++;
        }
    }

    return ans;
}

std::vector<int> Solution57::twoSum2(std::vector<int> &nums, int target) {
    std::vector<int> ans = {0, 0};

    // C++使用std::unordered_map构建hash表
    std::unordered_map<int, int> unorderedMap;
    int i = 0;

    // 如果遍历索引不超过数组size且遍历的数小于target
    while (nums[i] < target && i < nums.size()) {
        // 在哈希表中使用find()查找，如果能找到某个nums[j] = target - nums[i]
        // 则表示nums[i]和nums[j]的和为target
        if (unorderedMap.find(nums[i]) != unorderedMap.end()) {
            ans[0] = nums[i];
            ans[1] = target - nums[i];
            break;
        } else {
            // 以target-nums[i]为key存储进哈希表，
            unorderedMap[target - nums[i]] = nums[i];
        }

        i++;
    }
    return ans;
}
