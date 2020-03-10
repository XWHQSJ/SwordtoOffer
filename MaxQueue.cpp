//
// Created by Wanhui on 3/10/20.
//

#include "MaxQueue.h"

Solution59_2::Solution59_2() {}

int Solution59_2::max_value() {
    if(deq.empty()){
        return -1;
    }

    return deq.front();
}

void Solution59_2::push_back(int value) {
    while (!deq.empty() && deq.back() < value){
        deq.pop_back();
    }
    deq.push_back(value);
    que.push(value);
}

int Solution59_2::pop_front() {
    if(que.empty()){
        return -1;
    }

    int ans = que.front();
    if(ans == deq.front()){
        deq.pop_front();
    }
    que.pop();

    return ans;
}
