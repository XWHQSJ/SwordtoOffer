//
// Created by Wanhui on 2/22/20.
//

#ifndef SWORDTOOFFER_ISNUMBER_H
#define SWORDTOOFFER_ISNUMBER_H

/*
 * 剑指offer 20 表示数值的字符串
 *
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 *
 * 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"及"-1E-16"都表示数值，
 * 但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
 *
 * 还例如:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 *
 * 说明: 我们有意将问题陈述地比较模糊。
 * 在实现代码之前，你应当事先思考所有可能的情况。
 * 这里给出一份可能存在于有效十进制数字中的字符列表：
 *
 * 数字 0-9
 * 指数 - "e"
 * 正/负号 - "+"/"-"
 * 小数点 - "."
 *
 * 当然，在输入中，这些字符的上下文也很重要。
 * */


#include <string>

class Solution20 {
public:
    /*
     * 方法1 有限状态机(DFA)
     * 可通过编译原理中的有限状态机DFA解决，
     * 首先通过正则表达式构建DFA图(有限状态机.png)
     * ^\s*[\+\-]?(\d+\\.?\d*|\\.\d+)([eE][\+\-]?\d+)?\s*$
     * 再根据有限状态机的走向进行状态判断，
     * state表示遍历时的状态，flag处理特殊的 . ，
     * WARNing : 要去除字符串首尾可能存在的空字符
     * */
    bool isNumber(std::string s);

    /*
     * 方法2 正则表达式
     * 测试正则表达式的网址： https://ihateregex.io/playground
     * 匹配模式 ^\s*[\+\-]?(\d+\.?\d*|\.\d+)([eE][\+\-]?\d+)?\s*$
     * 有限状态机的状态图是从正则表达式中推出的，
     * 所以正则表达式可以解决
     * */
    bool isNumber2(std::string s);

    /*
     * 方法3 逐一判断
     * 遍历字符串，逐一判断每个字符是否满足条件，
     * 如果不满足返回false，满足继续往下判断
     * 可能会有想不到的条件，不可取
     * */
    bool isNumber3(std::string s);
};


#endif //SWORDTOOFFER_ISNUMBER_H
