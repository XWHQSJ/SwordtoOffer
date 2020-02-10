//
// Created by Wanhui on 2/9/20.
//

/*
 * This a main function for algorithms tests.
 * */

#include <iostream>
#include <assert.h>
#include "Find.h"

using namespace std;

int main()
{
    std::vector<std::vector<int>> array = {{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};
    int target = 9;
    Solution01 solution01;
    bool b = solution01.Find(target, array);
    // assert(b);
    std::cout << b << std::endl;

    return 0;
}



