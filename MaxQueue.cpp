//
// Created by Wanhui on 3/10/20.
//

#include "MaxQueue.h"

Solution59_2::Solution59_2() {}

// 取双端队列队首为当前普通队列中的最大值
int Solution59_2::max_value() {
    if (deq.empty()) {
        return -1;
    }

    return deq.front();
}

// 入队操作
void Solution59_2::push_back(int value) {
    // 保持双端队列中的队首元素为普通队列所有元素的最大值
    while (!deq.empty() && deq.back() < value) {
        deq.pop_back();
    }
    // 双端队列入队
    deq.push_back(value);

    // 普通队列正常入队
    que.push(value);
}

// 出队操作
int Solution59_2::pop_front() {
    if (que.empty()) {
        return -1;
    }

    // 如果当前要出队的队首元素，
    // 普通队首等于双端队首，
    // 则两队列队首都需要出队
    int ans = que.front();
    if (ans == deq.front()) {
        deq.pop_front();
    }
    que.pop();

    return ans;
}
