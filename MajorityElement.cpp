//
// Created by Wanhui on 2/28/20.
//

#include <cassert>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "MajorityElement.h"


int Solution39::majorityElement(std::vector<int> &nums) {
    assert(!nums.empty());
    std::unordered_map<int, int> unmap;
    for (auto it : nums) {
        unmap[it]++;
        if (unmap[it] > nums.size() / 2) {
            return it;
        }
    }

    return 0;
}

int Solution39::majorityElement2(std::vector<int> &nums) {
    assert(!nums.empty());
    std::sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
}

int Solution39::majorityElement3(std::vector<int> &nums) {
    assert(!nums.empty());

    return majority(nums, 0, nums.size() - 1);
}

int Solution39::majority(std::vector<int> &nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    // 数组中点
    int mid = left + (right - left) / 2;
    // 继续划分左边求值
    int leftmaj = majority(nums, left, mid);
    // 继续划分右边求值
    int rightmaj = majority(nums, mid + 1, right);

    // 划分到一个数，都相同则返回该数
    if (leftmaj == rightmaj) {
        return leftmaj;
    }

    // 计算它们的个数，并返回相应的数
    if(std::count(nums.begin() + left, nums.begin() + right + 1, leftmaj) >
       std::count(nums.begin() + 1, nums.begin() + right + 1, rightmaj)){
        return leftmaj;
    } else{
        return rightmaj;
    }
}


int Solution39::majorityElement4(std::vector<int> &nums) {
    assert(!nums.empty());

    // count计入当前队伍剩余人数
    // majority计入当前队伍人数
    int count = 0, majority = 0;
    for (auto num : nums) {
        // 当队伍人数为0时，记录下次遇到的队伍号
        if (!count) {
            majority = num;
        }

        // 判断是同队伍还是不同队伍
        if (num == majority) {
            // 同队伍，队员增加
            count += 1;
        } else {
            // 不同队伍，互相抵消
            count -= 1;
        }
    }

    return majority;
}

int Solution39::majorityElement5(std::vector<int> &nums) {
    assert(!nums.empty());

    int majority = 0;
    //
    for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
        int bits = 0;
        for (auto num : nums) {
            // nums中每个数的每一位与mask进行&操作
            // mask为1,所以bits计算每一列1的个数
            if (num & mask) {
                bits++;
            }
        }
        if (bits > nums.size() / 2) {
            // 如果majority和mask都为1则为1，
            // 反之为0
            majority |= mask;
        }
    }

    return majority;
}
