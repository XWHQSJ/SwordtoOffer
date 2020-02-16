//
// Created by Wanhui on 2/16/20.
//

#ifndef SWORDTOOFFER_CQUEUE_H
#define SWORDTOOFFER_CQUEUE_H

/*
 * 剑指offer 09 用两个栈实现队列
 *
 * 用两个栈实现一个队列。
 * 队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。
 * (若队列中没有元素，deleteHead 操作返回 -1 )
 *
 * 示例 1：
 *
 * 输入：
 * ["CQueue","appendTail","deleteHead","deleteHead"]
 * [[],[3],[],[]]
 *
 * 输出：[null,null,3,-1]
 *
 *
 * 示例 2：
 *
 * 输入：
 * ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
 * [[],[],[5],[2],[],[]]
 *
 * 输出：[null,-1,null,null,5,2]
 *
 * 提示：
 * 1 <= values <= 10000
 * 最多会对 appendTail、deleteHead 进行 10000 次调用
 * */

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

#include <stack>


/*
 * 这道题思路就是使用两个栈，
 * 一个栈添加元素，对应栈的push，
 * 一个栈删除元素，对应栈的pop。
 * 添加元素直接将数据push到栈1中即可。
 * 删除元素需要将栈1中的元素push到栈2中，
 * 达到数据逆序的目的，再取栈顶的元素并pop即可。
 * 但这里需要注意的是，如果栈2不空时，直接pop栈顶元素，
 * 不能将栈1新添加元素再push进来，
 * 即删除操作过程，每次必须要等到栈2空了才能从栈1push元素到栈2中。
 * */
class Solution09 {
public:
    Solution09();
    ~Solution09();

    void appendTail(int value);

    int deleteHead();

private:
    std::stack<int> stk1;
    std::stack<int> stk2;
};


#endif //SWORDTOOFFER_CQUEUE_H
