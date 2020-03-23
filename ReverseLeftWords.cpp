//
// Created by Wanhui on 3/23/20.
//

#include <algorithm>
#include "ReverseLeftWords.h"

std::string Solution58_2::reverseLeftWords(std::string s, int n) {
    if (s.empty()) {
        return s;
    }

    // 将n个字符组成字符串
    std::string tempStr;
    for (int i = 0; i < n; i++) {
        tempStr += s[i];
    }

    // 删除前n个字符
    s.erase(0, n);

    // 将旋转的临时字符串加到s字符串后面
    s += tempStr;

    return s;
}

std::string Solution58_2::reverseLeftWords2(std::string s, int n) {
    if (s.empty()) {
        return s;
    }

    // 三次原地翻转
    // 前n个字符组成的字符串翻转
    std::reverse(s.begin(), s.begin() + n);
    // 剩余字符组成的字符串翻转
    std::reverse(s.begin() + n, s.end());
    // 将字符串整体进行翻转
    std::reverse(s.begin(), s.end());

    return s;
}
