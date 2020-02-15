//
// Created by Wanhui on 2/15/20.
//

#include <algorithm>
#include "NthUglyNumber.h"

int Solution49::nthUglyNumber(int n) {
    std::vector<int> vec(n);
    int d2 = 0, d3 = 0, d5 = 0;
    vec[0] = 1;

    for (int i = 1; i < n; i++) {
        vec[i] = std::min(vec[d2] * 2, std::min(vec[d3] * 3, vec[d5] * 5));
        if (vec[i] == vec[d2] * 2) d2++;
        if (vec[i] == vec[d3] * 3) d3++;
        if (vec[i] == vec[d5] * 5) d5++;
    }

    return vec[n - 1];
}
