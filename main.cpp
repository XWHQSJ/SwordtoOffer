//
// Created by Wanhui on 2/9/20.
//

/*
 * This a main function for algorithms tests.
 * */

#include <iostream>
#include <assert.h>
#include "Find.h"
#include "Median.h"

using namespace std;

int main() {
    // Find.cpp test
    std::vector<std::vector<int>> array = {{1, 2, 3, 4},
                                           {2, 3, 4, 5},
                                           {3, 4, 5, 6},
                                           {4, 5, 6, 7}};
    int target = 9;
    Solution01 solution01;
    bool b = solution01.Find(target, array);
    // assert(b);
    std::cout << b << std::endl;

    // Median.cpp test
    Solution01_1 solution01_1;
    std::vector<unsigned int> arr = {2, 3, 4};
    int n = arr.size();
    int x = 2;
    int add = solution01_1.median(n, x, arr);
    std::cout << add << std::endl;

    return 0;
}

