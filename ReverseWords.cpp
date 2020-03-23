//
// Created by Wanhui on 3/23/20.
//

#include <stack>
#include <algorithm>
#include "ReverseWords.h"

std::string Solution58_1::reverseWords(std::string s) {
    if (s.empty()) {
        return s;
    }

    std::string ansStr;
    // 存储所有单词的栈
    std::stack<std::string> strStk;

    // 存放当前临时单词的字符串
    std::string tempStr;

    // 遍历字符串s
    for (char i : s) {
        // 如果当前字符不为空或结束字符
        if (i != ' ' && i != '\0') {
            // 则将当前字符加入当前临时单词中
            tempStr += i;
        } else {
            // 如果当前字符为空，
            // 且当前临时单词字符串大小不为0，
            // 则表示当前临时单词字符串对应的单词拼接完成
            if (tempStr.size() != 0) {
                // 将单词入栈
                strStk.push(tempStr);
            }

            // 重置当前临时单词字符串
            tempStr.clear();
        }
    }

    // 将字符串最后的单词入栈
    if (tempStr.size() != 0) {
        strStk.push(tempStr);
    }

    // 将栈顶单词和空字符串进行拼接
    while (!strStk.empty()) {
        ansStr += strStk.top() + " ";
        strStk.pop();
    }

    // 删除最后一个空字符
    ansStr = ansStr.substr(0, ansStr.size() - 1);

    return ansStr;
}

std::string Solution58_1::reverseWords2(std::string s) {
    if (s.empty()) {
        return s;
    }

    // 翻转字符串s
    std::reverse(s.begin(), s.end());
    // 删除字符串首尾的空字符
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);

    // 删除字符串单词间的多余1的空格
    // 定义快慢指针
    int fast = 1, slow = 0;
    while (slow < s.length()) {
        // 当慢指针和快指针同时指向空字符时
        if (s[slow] == ' ' && s[fast] == ' ') {
            // 如果有多于2的空字符，
            // 就将快指针继续后移，一直到不是空字符为止
            while (s[fast] == ' ') {
                fast++;
            }

            // 因为此时fast指向非空字符，
            // 则删掉除slow指向的空字符外的其它空字符
            // 删掉的空字符数为： fast - slow - 1
            s.erase(slow, fast - slow - 1);

            // slow指向空格，fast继续指向slow后面
            fast = slow + 1;
        } else {
            slow++;
            fast++;
        }
    }

    // 定义左右指针，对单词进行翻转
    // 右指针指向空字符串，左指针指向单词的第一个字符
    int left = 0, right = 0;
    while (right <= s.length()) {
        // 如果右指针指向空字符或结束字符
        if (s[right] == ' ' || s[right] == '\0') {
            // 就将该单词的所有字符进行翻转
            std::reverse(s.begin() + left, s.begin() + right);

            // 更新左指针的位置
            left = right + 1;
        }

        // 遍历单词
        right++;
    }

    return s;
}
