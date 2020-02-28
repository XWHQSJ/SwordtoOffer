//
// Created by Wanhui on 2/28/20.
//

#include <cassert>
#include "MinStack.h"

Solution30::Solution30() : stk({}), auxStk({}) {}

void Solution30::push(int x) {
    if (auxStk.empty() || x < auxStk.back()) {
        auxStk.push_back(x);
    } else {
        auxStk.push_back(auxStk.back());
    }

    stk.push_back(x);
}

void Solution30::pop() {
    assert(auxStk.size() > 0 && stk.size() > 0);

    auxStk.pop_back();
    stk.pop_back();
}

int Solution30::top() {
    assert(auxStk.size() > 0 && stk.size() > 0);

    return stk.back();;
}

int Solution30::min() {
    assert(auxStk.size() > 0 && stk.size() > 0);

    return auxStk.back();
}
