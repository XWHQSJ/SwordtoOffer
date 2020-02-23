//
// Created by Wanhui on 2/22/20.
//

#include "IsNumber.h"
#include <regex>

bool Solution20::isNumber(std::string s) {
    int state = 0, flag = 0;
    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    while (s[s.size() - 1] == ' ') {
        s.erase(s.size() - 1, 1);
    }

    if (s.empty()) {
        return false;
    }

    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            flag = 1;
            if (state <= 2) {
                state = 2;
            } else if (state <= 5) {
                state = 5;
            } else {
                state = 7;
            }
        } else if (s[i] == '+' || s[i] == '-') {
            if (state == 0 || state == 3) {
                state++;
            } else {
                return false;
            }
        } else if (s[i] == '.') {
            if (state <= 2) {
                state = 6;
            } else {
                return false;
            }
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (flag && (state == 2 || state == 6 || state == 7)) {
                state = 3;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return (state == 2 || state == 5 || (flag && state == 6) || state == 7);
}

bool Solution20::isNumber2(std::string s) {
    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    while (s[s.size() - 1] == ' ') {
        s.erase(s.size() - 1, 1);
    }

    if (s.empty()) {
        return false;
    }

    std::regex re(R"(^[\+\-]?(\d+\.\d+|\.\d+|\d+\.|\d+)(e[\+\-]?\d+)?$)");

    return std::regex_match(s, re);
}

bool Solution20::isNumber3(std::string s) {
    return false;
}
