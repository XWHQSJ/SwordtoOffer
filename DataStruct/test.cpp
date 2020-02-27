//
// Created by Wanhui on 2/26/20.
//

#include <iostream>
#include "DoubleNodeList.h"

int main(int argc, char *argv[]){
    DoubleNodeList<int> dnl;

    dnl.push_back(0);
    dnl.push_front(1);
    dnl.insert(1, 2);
    dnl.insert(1, 3);
    dnl.insert(3,4);
    dnl.insert(3,5);
    dnl.erase(2);
    dnl.insert(4,6);
    dnl.insert(3,7);
    dnl.insert(2,8);
    dnl.insert(5,9);
    dnl.insert(3,10);

    for(int i = 0; i < 10; i++){
        std::cout << dnl.at(i) << " : " << dnl[i] << std::endl;
    }

    for(int i = 0; i < 10; i++){
        std::cout << dnl.front() << std::endl;
        dnl.pop_front();
    }

    std::cout << dnl.size() << " : " << dnl.empty() << std::endl;
}

