//
// Created by Wanhui on 2/20/20.
//

#include "Exchange.h"

std::vector<int> Solution21::exchange(std::vector<int> &nums) {
    // []的处理
    if (nums.empty()) {
        return nums;
    }

    // 双指针lo,cur同侧，指针lo慢，指针cur快
    // 根据两指针的移动差别，对数据进行交换
    int lo = -1, cur = 0;

    while (cur < nums.size()) {
        // 当快指针指向的数据是奇数时
        if (nums[cur] & 1) {
            // 慢指针右移
            ++lo;
            // 将lo和cur指向的数据交换
            // 当前面都是奇数时，lo和cur所指向的数据相同
            // 保证cur指向右侧的奇数(cur指向左侧的偶数无法进入)时，
            // lo能指向左侧的偶数(lo在加1前一直待在左侧偶数的左边等待)
            std::swap(nums[lo], nums[cur]);
        }
        // 当左侧是偶数时，一直右移
        ++cur;
    }

    return nums;
}

std::vector<int> Solution21::exchange2(std::vector<int> &nums) {
    // []的处理
    if (nums.empty()) {
        return nums;
    }

    // 双指针low,high不同侧，low在左侧，high在右侧
    // 双指针根据条件不断朝中间移动
    int low = 0, high = nums.size() - 1;

    while (low != high) {
        // 当左侧为奇数，low不断向右侧移动
        while (low < high && nums[low] & 1) {
            low++;
        }

        // 当右侧为偶数，high不断向左侧移动
        while (low < high && ~nums[high] & 1) {
            high--;
        }

        // 当两指针不移动时，表明low指向偶数，high指向奇数
        // 此时两指针指向的数据交换
        std::swap(nums[low], nums[high]);
    }

    return nums;
}

std::vector<int> Solution21::exchange3(std::vector<int> &nums) {
    // []的处理
    if (nums.empty()) {
        return nums;
    }

    // WARNing : 不能初始化
    std::vector<int> arr;

    int i = 0;
    // 遍历第一遍，将奇数存在数组左侧
    for (i = 0; i < nums.size(); i++) {
        if ((nums[i] % 2) == 1) {
            arr.push_back(nums[i]);
        }
    }

    // 遍历第二遍，将偶数存在数组右侧
    for (i = 0; i < nums.size(); i++) {
        if ((nums[i] % 2) == 0) {
            arr.push_back(nums[i]);
        }
    }

    return arr;
}
