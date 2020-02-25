//
// Created by Wanhui on 2/25/20.
//

#ifndef SWORDTOOFFER_VALIDATESTACKSEQUENCES_H
#define SWORDTOOFFER_VALIDATESTACKSEQUENCES_H

/*
 * 剑指offer 31 栈的压入、弹出序列
 *
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。
 * 例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
 * 序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
 * 但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
 *
 * 示例 1：
 *
 * 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * 输出：true
 * 解释：我们可以按以下顺序执行：
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 *
 * 示例 2：
 *
 * 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * 输出：false
 * 解释：1 不能在 2 之前弹出。
 *
 * 提示：
 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed 是 popped 的排列。
 * */


#include <vector>

class Solution31 {
public:
    /*
     * 贪心算法
     *
     * 此题所用贪心法则为：
     * 如果栈顶元素等于popped序列中下一个要pop的值，
     * 则应立即将该值弹出
     *
     * 设置辅助栈来模拟栈的压入和弹出，
     * 对pushed序列遍历并依次压入辅助栈中，
     * 当辅助栈不空且其栈顶与popped序列第一个要弹出的值相等，
     * 则将该栈顶出栈，再判断栈不为空时，
     * 栈顶是否与popped序列第二个要弹出值相等，
     * 相等则弹出，继续上述操作，
     * 不相等时继续遍历pushed序列并压栈
     * */
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);
};


#endif //SWORDTOOFFER_VALIDATESTACKSEQUENCES_H
