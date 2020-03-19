//
// Created by Wanhui on 3/19/20.
//

#include <algorithm>
#include "MinNumber.h"

std::string Solution45::minNumber(std::vector<int> &nums) {
    if (nums.empty()) {
        return "";
    }

    // 存储数字转化后的字符串
    std::vector<std::string> numStr;
    // 结果字符串
    std::string resStr;

    // 将数组中的数转化为字符串
    for (int num : nums) {
        numStr.push_back(std::to_string(num));
    }

    // 对字符串数组中的字符串按照拼接比较规则进行排序
    std::sort(numStr.begin(), numStr.end(), compare);

    // 拼接最终的字符串结果
    for (std::string s : numStr) {
        resStr += s;
    }

    return resStr;
}

bool Solution45::compare(std::string &s1, std::string &s2) {
    // 小于的字符串拼接规则
    return (s1 + s2 < s2 + s1);
}
