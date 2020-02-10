//
// Created by Wanhui on 2/10/20.
//

#include "Median.h"

int Solution01_1::median(int n, unsigned int x, std::vector<unsigned int> arr) {

    int less = 0, high = 0, equal = 0;    //分别表示array中数与x比较的个数——小，大，等
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            ++equal;
        } else if (arr[i] < x) {
            ++less;
        } else {
            ++high;
        }
    }

    int add = 0;                        //需要增加的数的个数

    // 下面通过左边的数和右边的数进行抵消来判断增加的数
    if (less == high) {
        if (equal == 0) {
            add = 1;
        } else {
            add = 0;
        }
    } else if (less < high) {
        if ((high - less) < equal) {
            add = 0;
        } else {
            add = high - less - equal;
        }
    } else {
        if ((less - high) < equal) {
            add = 0;
        } else {
            add = less - high - equal + 1;          //这里注意是+1，因为索引从0开始
        }
    }

    return add;
}
