//
// Created by Wanhui on 3/21/20.
//

#include <unordered_map>
#include "Search.h"

int Solution53_1::search(std::vector<int> &nums, int target) {
    if (nums.empty()) {
        return 0;
    }

    // 哈希表存储数组中的数字和对应出现的次数
    std::unordered_map<int, int> unorderedMap;
    for (int num : nums) {
        unorderedMap[num]++;
    }

    // 查找哈希表中是否存在target，如果存储返回对应次数
    if (unorderedMap.find(target) != unorderedMap.end()) {
        return unorderedMap[target];
    } else {
        return 0;
    }
}


int Solution53_1::search2(std::vector<int> &nums, int target) {
    if (nums.empty()) {
        return 0;
    }

    int start = 0, end = nums.size() - 1;

    // 二分查找
    // target第一次出现的位置和最后一次出现的位置
    int firstT = -1, lastT = -1;

    // 查找target第一次的位置
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // 如果找到target
        if (nums[mid] == target) {
            // 如果target在第一次出现的位置
            if ((mid > 0 && nums[mid - 1] != target) || mid == 0) {
                // 返回第一次出现位置的索引
                firstT = mid;
                break;
            } else {
                end = mid - 1;
            }
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    // 查找target最后一次的位置
    start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // 如果找到target
        if (nums[mid] == target) {
            // 如果target在最后一次出现的位置
            if ((mid < nums.size() - 1 && nums[mid + 1] != target) || mid == nums.size() - 1) {
                // 返回最后一次出现位置的索引
                lastT = mid;
                break;
            } else {
                start = mid + 1;
            }
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // 使用最后一次的索引和第一次索引计算出现的次数
    if (firstT > -1 && lastT > -1) {
        return (lastT - firstT + 1);
    } else {
        return 0;
    }
}
