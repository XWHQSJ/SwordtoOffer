//
// Created by Wanhui on 3/10/20.
//

#ifndef SWORDTOOFFER_MAXQUEUE_H
#define SWORDTOOFFER_MAXQUEUE_H

/*
 * 剑指offer 59-II 队列的最大值
 *
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，
 * 要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 *
 * 示例 1：
 *
 * 输入:
 * ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
 * [[],[1],[2],[],[],[]]
 * 输出: [null,null,null,2,1,2]
 *
 * 示例 2：
 *
 * 输入:
 * ["MaxQueue","pop_front","max_value"]
 * [[],[],[]]
 * 输出: [null,-1,-1]
 *
 * 限制：
 * 1 <= push_back,pop_front,max_value的总操作数 <= 10000
 * 1 <= value <= 10^5
 * */

#include <queue>

class Solution59_2 {
public:
    Solution59_2();
    int max_value();
    void push_back(int value);
    int pop_front();

private:
    std::queue<int> que;
    std::deque<int> deq;
};


#endif //SWORDTOOFFER_MAXQUEUE_H