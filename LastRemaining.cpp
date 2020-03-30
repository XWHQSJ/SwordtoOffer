//
// Created by Wanhui on 3/25/20.
//

#include <list>
#include "LastRemaining.h"

int Solution62::lastRemaining(int n, int m) {
    if (n < 1 || m < 1) {
        return -1;
    }

    // 定义环形链表
    std::list<int> numList;

    // 将数插入到链表中
    for (int i = 0; i < n; i++) {
        numList.push_back(i);
    }

    // 定义当前遍历指针
    auto curIter = numList.begin();

    // 遍历链表中的数
    while (numList.size() > 1) {
        // 指引移动，直到第m个数
        for (int i = 1; i < m; i++) {
            curIter++;
            // 如果指针遍历到链表尾，将指针移到链表头进行循环
            if (curIter == numList.end()) {
                curIter = numList.begin();
            }
        }

        // 因为当前指针指向的数会被删除，
        // 定义指向下一个数的指针
        curIter++;
        auto nextIter = curIter;
        // 达到循环目的
        if (nextIter == numList.end()) {
            nextIter = numList.begin();
        }

        // 删除当前指针指向的数
        curIter--;
        numList.erase(curIter);

        // 当前指针指向下一个数
        curIter = nextIter;
    }

    return *curIter;
}

int Solution62::lastRemaining2(int n, int m) {
    if (n < 1 || m < 1) {
        return -1;
    }

    // 定义当前遍历指针
    std::list<int> numList;

    // 将数插入到链表中
    for (int i = 0; i < n; i++) {
        numList.push_back(i);
    }

    // 要删除的节点在链表中的索引
    int rmIdx = 0;

    // 遍历链表中的数
    while (numList.size() > 1) {
        // 每次都将指针重新定位到链表首节点
        auto iter = numList.begin();
        // 计算删除的节点索引
        // 通过模运算方式，能避免循环
        rmIdx = (rmIdx + m - 1) % numList.size();
        // 将指针从链表首部移动到索引处,
        // 此操作在线性时间内完成
        std::advance(iter, rmIdx);
        // 删除该索引处的节点
        numList.erase(iter);
    }

    return numList.front();
}

int Solution62::lastRemaining3(int n, int m) {
    if (n < 1 || m < 1) {
        return -1;
    }

    int ans = 0;
    // 根据数学递推的方式获得计算公式
    for (int i = 2; i <= n; i++) {
        ans = (ans + m) % i;
    }

    return ans;
}
