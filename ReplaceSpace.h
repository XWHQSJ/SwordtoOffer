//
// Created by Wanhui on 2/11/20.
//

#ifndef SWORDTOOFFER_REPLACESPACE_H
#define SWORDTOOFFER_REPLACESPACE_H

/*
 * 剑指offer 02 替换空格
 *
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.
 * 则经过替换之后的字符串为We%20Are%20Happy。
 * */

#include <string>

class Solution02 {
public:
    /*
     * 方法1
     * 先计算出空格的个数和字符数组原长，
     * 根据空格的个数，计算出替换后字符数组的长度，
     * 在设置两个指针p0,p1分别指向两个字符数组的末尾，
     * 指针p0一直向左遍历，指针p1也同时向左，
     * 当指针p0指向空格时，指针p1向左一次添加字符'%''2''0',
     * 直到指针p0到达原字符数组的开始处停止。
     *
     * 注意： s[i++] ==> s[i]; i+=1;
     *        s[++i] ==> i+=1; s[i];
     *
     * 该方法容易想到，但是字符处理需要非常注意！
     * */
    void replaceSpace(char *str, int length);

    /*
     * 方法2
     * 使用C语言中的strtok()函数，
     * 以空格为分割符，将字符数组分割为多部分，
     * std::string类可进行+操作，
     * 可以直接 + "%20"，
     * 再将分割的部分组合即可
     *
     * 注意： 组合后的字符串后面会多一个"%20"，
     * 需要重新赋值给char*数组后返回
     *
     * 该方法需要直到strok()的使用
     * */
    void replaceSpace1(char *str, int length);

    /*
     * 方法3
     * 重载函数类型，
     * 使用std::string类的操作更加方便
     * */
    std::string replaceSpace2(std::string s);

    /*
     * 方法4
     * 同方法3，
     * 根据std::string类的特性进行操作，
     * 简单易懂
     *
     * 注意： for(auto c : s) {} 的使用
     * */
    std::string replaceSpace3(std::string s);
};


#endif //SWORDTOOFFER_REPLACESPACE_H
