//
// Created by Wanhui on 3/12/20.
//

#include <vector>
#include <climits>
#include "StrToInt.h"

int Solution67::strToInt(std::string str) {
    int i = 0;

    // 处理首字符为空格的情况
    while (i < str.length()) {
        if (str[i] != ' ') {
            break;
        }

        i++;
    }
    str.erase(0, i);

    // 处理首字符为正负号的情况
    // 正负数标志
    int minus = 1;
    if (str[0] == '-') {
        minus = -1;
        str.erase(0, 1);
    } else if (str[0] == '+') {
        str.erase(0, 1);
    }

    // 处理字符串为空(包括删除完空格、正负号后)
    if (str.empty()) {
        return 0;
    }

    // 处理首字符不为数字的情况
    if (str[0] <= '0' || str[0] >= '9') {
        return 0;
    }

    long long int num = 0;
    i = 0;
    // 对字符串进行转化
    while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
        // 核心操作
        num = num * 10 + (str[i] - '0');

        // 处理整数溢出的情况
        if (minus * num > INT_MAX) {
            return INT_MAX;
        }

        if (minus * num < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    // 返回带符号的整数
    return num * minus;
}
