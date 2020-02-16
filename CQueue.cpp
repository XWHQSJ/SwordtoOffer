//
// Created by Wanhui on 2/16/20.
//


#include "CQueue.h"

Solution09::Solution09() = default;
Solution09::~Solution09() = default;

// 直接将添加的元素push到栈1
void Solution09::appendTail(int value) {
    stk1.push(value);
}

int Solution09::deleteHead() {
    if(stk1.empty() && stk2.empty()){
        return -1;
    }

    // 判断栈2是否为空，
    // 只有当栈2为空时，才能从栈1中push元素到栈2
    if(stk2.empty()){
        while (!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    // 当栈2不空时，直接pop栈2栈顶元素即可
    int d = stk2.top();
    stk2.pop();

    return d;
}



