//
// Created by Wanhui on 3/25/20.
//

#include <list>
#include "LastRemaining.h"

int Solution62::lastRemaining(int n, int m) {
    std::list<int> numList;

    for(int i = 0; i < n; i++){
        numList.push_back(i);
    }

    int i = 0;
    while (numList.size() > 1){
        if(i == m-1){

        }
    }

    return 0;
}
