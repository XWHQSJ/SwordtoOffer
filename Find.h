//
// Created by Wanhui on 2/9/20.
//

#ifndef SWORDTOOFFER_FIND_H
#define SWORDTOOFFER_FIND_H

/*
 * 剑指offer 01 二维数组的查找
 *
 * 在一个二维数组中（每个一维数组的长度相同），
 * 每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。
 *
 * 请完成一个函数，
 * 输入这样的一个二维数组和一个整数，
 * 判断数组中是否含有该整数。
 * */

#include <vector>

class Solution01{
public:

    /*
     * 二维数组的行和列都是有序一维数组，
     * 如果按照从左往右和从上往下比较，
     * 时间复杂度将是O(m*m)，m为目标值.
     * 将二维数组画图为矩阵考虑，
     * 可以发现从矩阵的最右上角或最左下角进行比较是最快的，
     * 当从最右上角从右到左进行比较时，行加列减
     * 当从最左下角从左到右进行比较时，列加行减
     * 由于r和c两个变量是条件变化的，
     * 使用while循环处理更加方便
     * */
    bool Find(int target, std::vector<std::vector<int> > array);
};

#endif //SWORDTOOFFER_FIND_H
