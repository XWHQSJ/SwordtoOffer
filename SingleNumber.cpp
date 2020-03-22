//
// Created by Wanhui on 3/22/20.
//

#include <unordered_map>
#include "SingleNumber.h"

int Solution56_2::singleNumber(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    // 哈希表存储数和其出现次数
    std::unordered_map<int, int> unorderedMap;
    for (int num : nums) {
        unorderedMap[num]++;
    }

    // 遍历哈希表
    for (auto iter : unorderedMap) {
        // 找到出现次数的数并返回
        if (iter.second == 1) {
            return iter.first;
        }
    }

    return 0;
}

int Solution56_2::singleNumber2(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    int ans = 0;
    // 存储所有数字二进制表示的每一位的和
    int bitSum[32] = {0};
    // 该位是0或1
    int bit = 0;

    // 遍历数组中的数
    for (int num : nums) {
        // 每次更新无符号整数掩码为1
        unsigned int bitMask = 1;
        // 对数字的32位进行累加，从低位开始
        for (int i = 31; i >= 0; i--) {
            // 计算该位是1还是0
            bit = num & bitMask;
            // 如果不是0，则将存储每位和的数组的该位加1
            if (bit != 0) {
                bitSum[i] += 1;
            }

            // 将掩码的1左移，接着计算右起开始的下一位
            bitMask <<= 1;
        }
    }

    // 遍历二进制每一位和的数组，从高位开始
    for (int b : bitSum) {
        // 考虑到最后一位的情况，
        // 应该先左移再计算
        ans <<= 1;
        // 如果和的该位整除3则为0，
        // 否则为1
        ans += (b % 3);
    }

    return ans;
}
