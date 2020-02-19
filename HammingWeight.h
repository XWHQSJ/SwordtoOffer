//
// Created by Wanhui on 2/18/20.
//

#ifndef SWORDTOOFFER_HAMMINGWEIGHT_H
#define SWORDTOOFFER_HAMMINGWEIGHT_H

/*
 * 剑指offer 15 二进制中1的个数
 *
 * 请实现一个函数，输入一个整数，
 * 输出该数二进制表示中 1 的个数。
 * 例如，把 9 表示成二进制是 1001，有 2 位是 1。
 * 因此，如果输入 9，则该函数输出 2。
 *
 * 示例 1：
 *
 * 输入：00000000000000000000000000001011
 * 输出：3
 * 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
 *
 * 示例 2：
 *
 * 输入：00000000000000000000000010000000
 * 输出：1
 * 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
 *
 * 示例 3：
 *
 * 输入：11111111111111111111111111111101
 * 输出：31
 * 解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
 * */


#include <cstdint>

class Solution15 {
public:
    /*
     * 方法1 遍历移位
     * n&1表示判断n二进制的最后一位数是否为1，
     * 如果n&1=1表示n二进制最后一位为1，
     * 反之n&1=0，
     * 所以通过n&1可以判断n二进制的每一位是否为1，
     * 循环的处理可以通过移位或除2进行，
     * 再判断是否为1
     *
     * 输入的如果是负数，不经过(unsigned int)强制转化，
     * 使用位移操作则循环就会无限下去
     * */
    int hammingWeight(int n);
    /*
     * 方法2 汉明重量法
     * 通过汉明重量，
     * 对数据进行特殊的运算，
     * 有几种汉明重量的计算方式
     *
     * 百度“汉明重量”
     * https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E9%87%8D%E9%87%8F
     * */
    int hammingWeight2(uint32_t n);
    int hammingWeight3(uint32_t n);
    int hammingWeight4(uint32_t n);
    int hammingWeight5(uint32_t n);

    //针对0比较多情况下的优化
    int hammingWeight6(uint32_t n);
    int hammingWeight7(uint32_t n);

private:
    const uint32_t m1 = 0x55555555;
    const uint32_t m2 = 0x33333333;
    const uint32_t m4 = 0x0f0f0f0f;
    const uint32_t m8 = 0x00ff00ff;
    const uint32_t m16 = 0x0000ffff;
    const uint32_t hff = 0xffffffff;
    const uint32_t h01 = 0x01010101;

};


#endif //SWORDTOOFFER_HAMMINGWEIGHT_H
