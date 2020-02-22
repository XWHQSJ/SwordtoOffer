//
// Created by Wanhui on 2/22/20.
//

#include "IsNumber.h"
#include <regex>

bool Solution20::isNumber(std::string s) {
    bool sign = false, decimal = false, haveE = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'e' || s[i] == 'E') {
            if (i == s.size() - 1 || i == 0) {
                return false;
            }
            if (haveE) {
                return false;
            }

            haveE = true;
        } else if (s[i] == '+' || s[i] == '-') {
            if (sign && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
            if (!sign && i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }

            sign = true;
        } else if (s[i] == '.') {
            if (haveE || decimal) {
                return false;
            }
            if (i == s.size() - 1 || i == 0) {
                return false;
            }
            decimal = true;
        } else if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}
