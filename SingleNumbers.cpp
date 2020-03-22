//
// Created by Wanhui on 3/22/20.
//

#include "SingleNumbers.h"

std::vector<int> Solution56_1::singleNumbers(std::vector<int> &nums) {
    if (nums.empty()) {
        return {};
    }

    // 结果数组
    std::vector<int> ans(2, 0);

    // 对数组中的数从头到尾进行异或
    // 计算最终异或结果
    int xorResult = 0;
    for (int num : nums) {
        xorResult ^= num;
    }

    // 计算最终结果从右数的第一个为1的位
    int index = 0;
    while (((xorResult & 1) == 0) && (index < 8 * sizeof(int))) {
        xorResult >>= 1;
        index++;
    }

    // 按照计算的1的位，将数组中的数分为两组
    for (int num : nums) {
        // 右移到index位，与1
        // 判断该位是否为1
        if ((num >> index) & 1) {
            // 将该组数从头到尾进行异或
            ans[0] ^= num;
        } else {
            // 将该组数从头到尾进行异或
            ans[1] ^= num;
        }
    }

    return ans;
}
