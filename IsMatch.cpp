//
// Created by Wanhui on 2/21/20.
//

#include <vector>
#include "IsMatch.h"

bool Solution19::isMatch(std::string s, std::string p) {
    if (p.empty()) {
        return s.empty();
    }

    // p,s第一个字符是否匹配，相等或为 '.'
    bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

    // 从p的第2个字符开始，如果为 '*'
    if (p.size() >= 2 && p[1] == '*') {
        // 考虑 '*' 表示前面字符0次和多次的情况
        // 0次：s回溯与p第3个字符继续下一轮匹配
        // 多次 : 第1个字符匹配，从s第2个字符与p继续下一轮匹配
        return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
    } else {
        //未匹配到 '*'，继续普通匹配
        return first_match && isMatch(s.substr(1), p.substr(1));
    }
}

bool Solution19::isMatch2(std::string s, std::string p) {
    if (p.empty()) {
        return s.empty();
    }

    // 前面加某一相同字符，
    // 防止 (ab, c*ab) 这样的匹配，
    // 避免复杂的初始化操作
    s = " " + s;
    p = " " + s;
    int m = s.size(), n = p.size();

    // 定义记忆数组，并初始化为false
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

    // 设添加的字符为真
    dp[0][0] = true;

    // 记忆数组能保持字符串上一个字符的状态
    // 因此可以对下一个字符进行判断
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            // 不带 '*' 号时的匹配
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // 考虑 '*' 时的两种情况
                if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                    dp[i][j] = dp[i][j - 2];
                } else {
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
    }

    // 返回最后字符的匹配状态
    return dp[m][n];
}
