//
// Created by Wanhui on 2/11/20.
//

#include <malloc.h>
#include <cstring>
#include <iostream>
#include "ReplaceSpace.h"

void Solution02::replaceSpace(char *str, int length) {
    if (str == nullptr || length < 0) {
        return;
    }

    int originlen = 0;
    int newlen = 0;
    int spacenum = 0;
    while (str[originlen] != '\0') {
        if (str[originlen] == ' ') {
            spacenum++;
        }
        originlen++;
    }

    newlen = originlen + spacenum * 2;

    while (originlen >= 0 && newlen >= 0) {
        if (str[originlen] == ' ') {
            str[newlen--] = '0';
            str[newlen--] = '2';
            str[newlen--] = '%';
        } else {
            str[newlen--] = str[originlen];
            //newlen -= 1;
        }
        originlen--;
    }
}

void Solution02::replaceSpace1(char *str, int length) {
    const char *sep = " ";
    char *ptr = nullptr;
    ptr = strtok(str, sep);
    std::string sss;

    while (ptr) {
        sss = sss + ptr + "%20";
        ptr = strtok(nullptr, sep);
    }

    for (int i = 0; i < sss.size() - 3; ++i) {
        str[i] = sss[i];
    }
}

std::string Solution02::replaceSpace2(std::string s) {
    int i = 0;
    std::string str;

    while (i < s.size()) {
        if (s[i] == ' ') {
            str.push_back('%');
            str.push_back('2');
            str.push_back('0');
        } else {
            str.push_back(s[i]);
        }
        i++;
    }

    return str;
}

std::string Solution02::replaceSpace3(std::string s) {
    std::string str;

    for (auto c : s) {
        if (c == ' ') {
            str += "%20";
        } else {
            str += c;
        }
    }

    return str;
}


