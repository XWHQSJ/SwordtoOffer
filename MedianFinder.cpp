//
// Created by Wanhui on 2/29/20.
//

#include <algorithm>
#include "MedianFinder.h"

Solution41::Solution41() : nums(), qmax(), qmin(), mid(data.end()) {}

void Solution41::addNum(int num) {
    nums.push_back(num);
}

double Solution41::findMedian() {
    if (nums.empty()) {
        return 0;
    }

    // 使用std::sort()函数对数组进行简单排序
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    // 总数为奇数时直接取中值
    // 总数为偶数时取中间两值的平均数
    if (n & 1) {
        return nums[n / 2];
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
}


void Solution41::addNum2(int num) {
    // 数组为空时添加元素
    if (nums.empty()) {
        nums.push_back(num);
    } else {
        // 先使用std::lower_bound()找到nums范围内不小于num的数的位置
        // 在该位置前使用std::insert()插入num
        nums.insert(std::lower_bound(nums.begin(), nums.end(), num), num);
    }
}

double Solution41::findMedian2() {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    // 总数为奇数时直接取中值
    // 总数为偶数时取中间两值的平均数
    if (n & 1) {
        return nums[n / 2];
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
}


void Solution41::addNum3(int num) {
    // 先将元素添加到大顶堆
    qmax.push(num);

    // 再将大顶堆的堆顶即最大元素添加到小顶堆
    qmin.push(qmax.top());
    // 大顶堆中弹出刚刚添加到小顶堆中的数
    qmax.pop();

    // 如果大顶堆数量比小顶堆少
    // （理想情况是大顶堆数量比小顶堆大1或相等）
    if (qmax.size() < qmin.size()) {
        // 则将小顶堆堆顶即最小元素添加到大顶堆
        qmax.push(qmin.top());
        // 小顶堆中弹出刚刚添加到大顶堆中的数
        qmin.pop();
    }
}

double Solution41::findMedian3() {
    // 大顶堆数量大于小顶堆1个，取大顶堆堆顶
    // 大顶堆数量等于小顶堆，取两堆堆顶平均数
    if (qmax.size() > qmin.size()) {
        return qmax.top();
    } else {
        return (qmax.top() + qmin.top()) / 2;
    }
}

void Solution41::addNum4(int num) {
    // 当前平衡二叉搜索树的元素数量
    const int n = data.size();
    // 添加元素num
    data.insert(num);

    // 如果n=0,即树为空，添加第一个元素
    //
    // 如果添加元素小于当前中位数，
    // 若当前树大小为奇数，则中位数不变
    // 若当前树大小为偶数，则中位数为原中位数的前1个元素
    //
    // 如果添加元素大于等于当前中位数，
    // 若当前树大小为奇数，则中位数为原中位数的后1个元素
    // 若当前树大小为偶数，则中位数不变
    if (!n) {
        mid = data.begin();
    } else if (num < *mid) {
        mid = (n & 1 ? mid : std::prev(mid));
    } else {
        mid = (n & 1 ? std::next(mid) : mid);
    }
}

double Solution41::findMedian4() {
    const int n = data.size();
    // n % 2 - 1 为0时，表示树大小为奇数，此时返回中位数mid
    // n % 2 - 1 为-1时，表示树大小为偶数，此时返回*mid和mid前1个元素的和的均值
    return (*mid + *std::next(mid, n % 2 - 1)) / 2;
}
