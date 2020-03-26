//
// Created by Wanhui on 3/25/20.
//

#include <list>
#include "LastRemaining.h"

int Solution62::lastRemaining(int n, int m) {
    if (n < 1 || m < 1) {
        return -1;
    }

    std::list<int> numList;

    for (int i = 0; i < n; i++) {
        numList.push_back(i);
    }

    auto curIter = numList.begin();

    while (numList.size() > 1) {
        for (int i = 1; i < m; i++) {
            curIter++;
            if (curIter == numList.end()) {
                curIter = numList.begin();
            }
        }

        curIter++;
        auto nextIter = curIter;
        if (nextIter == numList.end()) {
            nextIter = numList.begin();
        }

        curIter--;
        numList.erase(curIter);
        curIter = nextIter;
    }

    return *curIter;
}

int Solution62::lastRemaining2(int n, int m) {
    return 0;
}
