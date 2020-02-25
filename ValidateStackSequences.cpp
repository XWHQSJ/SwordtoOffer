//
// Created by Wanhui on 2/25/20.
//

#include <stack>
#include "ValidateStackSequences.h"

bool Solution31::validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped) {
    if(pushed.size() != popped.size()){
        return false;
    }

    std::stack<int> stk;
    int m = pushed.size();
    int index = 0;

    // 对pushed序列元素遍历
    for(int i = 0; i < m; i++){
        // 将pushed元素依次压入辅助栈
        stk.push(pushed[i]);

        // 当栈不为空且栈顶元素等于popped序列下一个要弹出的元素
        while (!stk.empty() && stk.top() == popped[index]){
            // 立即弹出该元素
            stk.pop();
            // popped索引加1，指向下一个要弹出元素
            index++;
        }
    }

    // 判断栈是否为空，为空则是有效弹出序列
    return stk.empty();
}

