//
// Created by Wanhui on 3/27/20.
//

#include "ConstructArr.h"

std::vector<int> Solution66::constructArr(std::vector<int> &a) {
    if (a.empty()) {
        return {};
    }

    std::vector<int> ans(a.size(), 1);

    // 计算该数左边所有数的乘积，存储到该数
    for (int i = 1; i < a.size(); i++) {
        ans[i] = ans[i - 1] * a[i - 1];
    }

    // 再计算该数右边所有数的乘积，存到temp
    int temp = 1;
    for (int i = a.size() - 2; i >= 0; i--) {
        temp *= a[i + 1];
        // 最后将temp乘该数
        ans[i] *= temp;
    }

    return ans;
}
