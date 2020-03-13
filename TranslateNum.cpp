//
// Created by Wanhui on 3/13/20.
//


#include <string>
#include "TranslateNum.h"

int Solution46::translateNum(int num) {
    // num小于0，不可翻译
    if (num < 0) {
        return 0;
    }

    // num只有一个数字，也就只有一种翻译
    if (num < 10) {
        return 1;
    }

    // 将num转化为字符串，方便判断
    std::string numStr = std::to_string(num);

    // 存储状态的数组
    int *dp = new int[numStr.length()];

    // 初始化初始状态
    dp[0] = 1;

    if (numStr[0] == '0' || numStr.substr(0, 2) > "25") {
        dp[1] = 1;
    } else {
        dp[1] = 2;
    }

    // 根据状态方程，求每个字符下的翻译种数
    for (int i = 2; i < numStr.length(); i++) {
        // 前一个字符为0或两个字符合并大于25时，
        // 当前字符下的翻译种数等于前一字符下的翻译种数
        if (numStr[i - 1] == '0' || numStr.substr(i - 1, 2) > "25") {
            dp[i] = dp[i - 1];
        } else {
            // 当前字符下的翻译种数等于前一字符下的翻译种数
            // 加上前前一字符下的翻译种数
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    // 保存最终结果
    int count = dp[numStr.length() - 1];

    // 释放数组
    delete[]dp;
    // 避免野指针
    dp = nullptr;

    return count;
}
