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
    /*
     * 单调双端队列
     *
     * 使用双端队列实现一个单调队列，使队列中的数始终保持递减，则双端队列的队首元素始终为最大值。
     * 同时使用普通队列存储输入的数，当对普通队列中的元素做出队操作时，
     * 需要考虑普通队列的队首元素是否与双端队列的队首元素相等，如果相等，则双端队列的队首元素也要出队，
     * 这样才能始终保证双端队列的队首是当前普通队列中所有元素的最大值。
     * */

    Solution59_2();

    int max_value();

    void push_back(int value);

    int pop_front();

private:
    // 定义普通队列
    std::queue<int> que;
    // 定义双端队列
    std::deque<int> deq;
};


#endif //SWORDTOOFFER_MAXQUEUE_H
