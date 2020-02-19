//
// Created by Wanhui on 2/9/20.
//

/*
 * This a main function for algorithms tests.
 * */

#include <iostream>
#include <cassert>
#include "FindNumberIn2DArray.h"
#include "Median.h"
#include "ReplaceSpace.h"
#include "FindRepeatNumber.h"
#include "ReversePrint.h"
#include "NthUglyNumber.h"
#include "BuildTree.h"
#include "CQueue.h"
#include "Fibonacci.h"
#include "NumWays.h"
#include "MinArray.h"
#include "Exist.h"
#include "HammingWeight.h"

using namespace std;

int main() {
    // FindNumberIn2DArray.cpp test
    std::vector<std::vector<int>> array = {{1, 2, 3, 4},
                                           {2, 3, 4, 5},
                                           {3, 4, 5, 6},
                                           {4, 5, 6, 7}};
    int target = 9;
    Solution04 solution04;
    bool b = solution04.findNumberIn2DArray(target, array);
    // assert(b);
    std::cout << b << std::endl;

    // Median.cpp test
    Solution04_1 solution04_1;
    std::vector<unsigned int> arr = {2, 3, 4};
    int n = arr.size();
    int x = 2;
    int add = solution04_1.median(n, x, arr);
    std::cout << add << std::endl;

    // ReplaceSpace.cpp test
    Solution05 solution05;
    char str[] = "hello world";
    int length = sizeof(str) / sizeof(str[0]);
    solution05.replaceSpace1(str, length);
    for (int i = 0; i < 13; ++i) {
        std::cout << str[i];
    }
    std::cout << "\n";

    char str2[] = "Hello World";
    solution05.replaceSpace(str2, length);
    for (int i = 0; i < 13; ++i) {
        std::cout << str2[i];
    }
    std::cout << "\n";

    std::string s = "Hello world";
    std::string str3;
    str3 = solution05.replaceSpace2(s);
    std::cout << str3 << std::endl;

    std::string str4;
    str4 = solution05.replaceSpace2(s);
    std::cout << str4 << std::endl;


    // FindRepeatNumber.cpp test
    Solution03 solution03;
    std::vector<int> vec = {2, 3, 1, 0, 2, 5, 3};
    int num;
    num = solution03.findRepeatNumber(vec);
    std::cout << num << std::endl;

    num = solution03.findRepeatNumber3(vec);
    std::cout << num << std::endl;

    num = solution03.findRepeatNumber2(vec);
    std::cout << num << std::endl;


    // ReversePrint.cpp test
    Solution06 solution06;
    std::vector<int> val;


    // BuildTree.cpp test
    Solution07 solution07;


    // CQueue.cpp test
    Solution09 solution09;
    solution09.appendTail(3);
    solution09.appendTail(4);
    solution09.appendTail(5);
    int c = solution09.deleteHead();
    std::cout << c << std::endl;


    // Fibonacci.cpp test
    Solution10_1 solution10_1;
    int n3 = 5;
    int f = solution10_1.fibonacci(n3);
    std::cout << f << std::endl;

    f = solution10_1.fibonacci2(n3);
    std::cout << f << std::endl;


    // NumWays.cpp test
    Solution10_2 solution10_2;
    int n2 = 7;
    f = solution10_2.numWays(n2);
    std::cout << f << std::endl;

    f = solution10_2.numWays2(n2);
    std::cout << f << std::endl;


    // MinArray.cpp test
    Solution11 solution11;
    std::vector<int> num1 = {3, 4, 5, 1, 2};
    std::vector<int> num2 = {2, 2, 2, 0, 1};
    int m2 = solution11.minArray(num1);
    std::cout << m2 << std::endl;
    m2 = solution11.minArray2(num1);
    std::cout << m2 << std::endl;


    // Exit.cpp test
    Solution12 solution12;
    std::vector<std::vector<char>> board1 = {{'A', 'B', 'C', 'E'},
                                             {'S', 'F', 'C', 'S'},
                                             {'A', 'D', 'E', 'E'}};
    std::string word1 = "ABCCED";
    std::vector<std::vector<char>> board2 = {{'a', 'b'},
                                             {'c', 'd'}};
    std::string word2 = "abcd";
    std::vector<std::vector<char>> board3 = {{'a'}};
    std::string word3 = "ab";
    bool b1 = solution12.exist(board1, word1);
    std::cout << "b1 = " << b1 << std::endl;
    b1 = solution12.exist(board2, word2);
    if (!b1) {
        std::cout << "b1 = " << 0 << std::endl;
    }
    b1 = solution12.exist(board3, word3);
    if (!b1) {
        std::cout << "b1 = " << 0 << std::endl;
    }


    // HammingWeight.cpp test
    Solution15 solution15;
    uint32_t n4 = 00000000000000000000000000001011;
    uint32_t n5 = 00000000000000000000000010000000;
    uint32_t n6 = 9;
    int n7 = -3;
    int m3 = solution15.hammingWeight(n7);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight2(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight3(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight4(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight5(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight6(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight7(n6);
    std::cout << "m3 = " << m3 << std::endl;


    // NthUglyNumber.cpp test
    Solution49 solution49;
    int n1 = 10;
    int m = 0;
    m = solution49.nthUglyNumber(n1);
    std::cout << m << std::endl;

    return 0;
}

