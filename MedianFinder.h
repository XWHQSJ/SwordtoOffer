//
// Created by Wanhui on 2/29/20.
//

#ifndef SWORDTOOFFER_MEDIANFINDER_H
#define SWORDTOOFFER_MEDIANFINDER_H

/*
 * 剑指offer 41 数据流中的中位数
 *
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
 * 那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，
 * 那么中位数就是所有数值排序之后中间两个数的平均值。
 *
 * 例如，
 *
 * [2,3,4] 的中位数是 3
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 *
 * 设计一个支持以下两种操作的数据结构：
 *
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 *
 * 示例 1：
 *
 * 输入：
 * ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
 * [[],[1],[2],[],[3],[]]
 * 输出：[null,null,null,1.50000,null,2.00000]
 *
 * 示例 2：
 *
 * 输入：
 * ["MedianFinder","addNum","findMedian","addNum","findMedian"]
 * [[],[2],[],[3],[]]
 * 输出：[null,null,2.00000,null,2.50000]
 *
 * 限制：
 * 最多会对 addNum、findMedia进行 50000 次调用。
 *
 * 进阶:
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * */


#include <vector>
#include <queue>
#include <set>

/*
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 * */
class Solution41 {
private:
    std::vector<double> nums;

    // 大顶堆
    std::priority_queue<double> qmax;
    // 小顶堆
    std::priority_queue<double, std::vector<double>, std::greater<>> qmin;

    // 平衡二叉搜索树
    std::multiset<double> data;
    std::multiset<double>::iterator mid;

public:
    /*
     * 方法一 简单排序法 O(nlogn) 超时
     *
     * 每添加一个数，就对当前数组进行排序std::sort()，
     * 判断数组大小为奇偶数，再取数组中间的值
     * */

    Solution41();

    void addNum(int num);
    double findMedian();


    /*
     * 方法二 插入排序法 O(n)
     *
     * 每添加一个数，先在之前的数组中找到不小于该数的数的位置std::lower_bound()，
     * 再在找到的数的位置处插入添加的数std::insert()，则数组一直保持有序，
     * 二份查找时间O(logn)，插入时间为O(n)
     * */
    void addNum2(int num);
    double findMedian2();


    /*
     * 方法三 大小顶堆法(优先队列) O(logn)
     *
     * 设置一个大顶堆存储较小的一半数，
     * 设置一个小顶堆存储较大的一半数，
     * 则两个堆堆顶节点必为数组中间元素。
     *
     * 而要保持大顶堆和小顶堆平衡，
     * 则大顶堆节点数量最多比小顶堆多一个或少一个，
     * 如果总共插入了k个元素，则有：
     * 1. k = 2*n + 1;    大顶堆n+1个，小顶堆n个；
     * 2. k = 2*n;        大顶堆和小顶堆都为n个。
     *
     * 这样若数组大小为奇数时，中位数为大顶堆的堆顶；
     * 数组大小为偶数时，中位数为大顶堆和小顶堆堆顶和的一半。
     *
     * 每添加一个数num时，
     * 1. 将num添加到大顶堆，此时大顶堆比小顶堆多一个元素，
     *    为保持小顶堆平衡，从大顶堆中取堆顶，添加到小顶堆中；
     * 2. 在操作1后，小顶堆可能比大顶堆保留更多元素，
     *    为保持大顶堆平衡，从小顶堆取堆顶，添加到大顶堆。
     *
     * 举例：输入[41, 35, 62, 4, 97, 108]
     * Adding number 41
     * MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
     * MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
     * Median is 41
     * =======================
     * Adding number 35
     * MaxHeap lo: [35]
     * MinHeap hi: [41]
     * Median is 38
     * =======================
     * Adding number 62
     * MaxHeap lo: [41, 35]
     * MinHeap hi: [62]
     * Median is 41
     * =======================
     * Adding number 4
     * MaxHeap lo: [35, 4]
     * MinHeap hi: [41, 62]
     * Median is 38
     * =======================
     * Adding number 97
     * MaxHeap lo: [41, 35, 4]
     * MinHeap hi: [62, 97]
     * Median is 41
     * =======================
     * Adding number 108
     * MaxHeap lo: [41, 35, 4]
     * MinHeap hi: [62, 97, 108]
     * Median is 51.5
     *
     * 最坏情况下，从顶部有三个堆插入两个堆删除，每个需要O(logn)
     * */
    void addNum3(int num);
    double findMedian3();


    /*
     * 方法四 平衡二叉搜索树法(AVL树) O(logn)
     *
     * 平衡二叉搜索树将树的高度保持在对数范围内，
     * 中位数在树根或它的一个子树上。
     * 使用multiset类模拟平衡二叉树的行为，
     * 同时保持两个指针，一个用于较中位数低的元素，
     * 另一个用于较中位数高的元素。
     * 当数组总数为奇数时，两指针指向同一中值元素;
     * 当数组总数为偶数时，指针指向两元素的平均值为中位数。
     *
     * 平衡二叉搜索树的构建是O(logn)
     * */
    void addNum4(int num);
    double findMedian4();
};


#endif //SWORDTOOFFER_MEDIANFINDER_H
