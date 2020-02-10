//
// Created by Wanhui on 2/9/20.
//

#include "Find.h"
#include <iostream>

bool Solution01::Find(int target, std::vector<std::vector<int> > array) {
    int rows = array.size();
    int cols = array[0].size();

    if (array.empty()) {
        return false;
    }

    int r = 0;
    int c = cols - 1;

    while (r < rows && c >= 0) {
        if (array[r][c] == target) {
            return true;
        } else if (array[r][c] > target) {
            --c;
        } else {
            ++r;
        }
    }

    return false;
}
