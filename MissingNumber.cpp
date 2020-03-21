//
// Created by Wanhui on 3/21/20.
//

#include "MissingNumber.h"

int Solution53_2::missingNumber(std::vector<int> &nums) {
    if (nums.empty()) {
        return -1;
    }

    // 定义次数数组（桶）
    std::vector<int> count(nums.size() + 1, 0);

    // 将数出现的次数存放在数对应的索引上
    for (int num : nums) {
        count[num]++;
    }

    // 遍历次数数组，如果次数为0表示该索引对应的数缺失
    for (int i = 0; i < count.size(); i++) {
        if (count[i] == 0) {
            return i;
        }
    }

    return -1;
}

int Solution53_2::missingNumber2(std::vector<int> &nums) {


    return 0;
}
