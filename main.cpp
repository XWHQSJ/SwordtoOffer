//
// Created by Wanhui on 2/9/20.
//

/*
 * This a main function for algorithms tests.
 * */

#include <iostream>
#include <assert.h>
#include "FindNumberIn2DArray.h"
#include "Median.h"
#include "ReplaceSpace.h"

using namespace std;

int main() {
    // Find.cpp test
    std::vector<std::vector<int>> array = {{1, 2, 3, 4},
                                           {2, 3, 4, 5},
                                           {3, 4, 5, 6},
                                           {4, 5, 6, 7}};
    int target = 9;
    Solution01 solution01;
    bool b = solution01.findNumberIn2DArray(target, array);
    // assert(b);
    std::cout << b << std::endl;

    // Median.cpp test
    Solution01_1 solution01_1;
    std::vector<unsigned int> arr = {2, 3, 4};
    int n = arr.size();
    int x = 2;
    int add = solution01_1.median(n, x, arr);
    std::cout << add << std::endl;

    // ReplaceSpace.cpp test
    Solution02 solution02;
    char str[] = "hello world";
    int length = sizeof(str) / sizeof(str[0]);
    solution02.replaceSpace1(str, length);
    for (int i = 0; i < 13; ++i) {
        std::cout << str[i];
    }
    std::cout << "\n";

    char str2[] = "Hello World";
    solution02.replaceSpace(str2, length);
    for (int i = 0; i < 13; ++i) {
        std::cout << str2[i];
    }
    std::cout << "\n";

    std::string s = "Hello world";
    std::string str3;
    str3 = solution02.replaceSpace2(s);
    std::cout << str3 << std::endl;

    std::string str4;
    str4 = solution02.replaceSpace2(s);
    std::cout << str4 << std::endl;

    return 0;
}

