//
// Created by Wanhui on 2/28/20.
//

#ifndef SWORDTOOFFER_MINSTACK_H
#define SWORDTOOFFER_MINSTACK_H

/*
 * 剑指offer 30 包含min函数的栈
 *
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
 * 调用 min、push 及 pop 的时间复杂度都是 O(1)。
 *
 * 示例:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.min();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.min();   --> 返回 -2.
 *
 * 提示：
 * 各函数的调用总次数不超过 20000 次
 * */


/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 * */

#include <vector>

class Solution30 {
public:
    /*
     * 辅助栈法
     *
     * 一开始想到设置成员变量来存储压入栈的最小值，
     * 但当该最小值弹出后，最小值就需要更新，
     * 所以此方法不完善，遂想到使用一个辅助栈来存储历来的最小值，
     * 即每压入一个数，就将该次的最小值压入辅助栈，
     * 没弹出一个值，如果该值为最小值，辅助栈就弹出栈顶，
     * 所以能够保持辅助栈的栈顶必为最小值。
     * */
    Solution30();

    void push(int x);

    void pop();

    int top();

    int min();

private:
    std::vector<int> stk;
    std::vector<int> auxStk;
};


#endif //SWORDTOOFFER_MINSTACK_H
