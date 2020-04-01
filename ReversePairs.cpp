//
// Created by Wanhui on 3/22/20.
//

#include "ReversePairs.h"

int Solution51::reversePairs(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    // 合并数组用
    std::vector<int> copyNums(nums.size(), 0);

    // 逆序对的个数
    int count = 0;
    mergeSort(nums, copyNums, 0, nums.size() - 1, count);

    return count;
}

void Solution51::mergeSort(std::vector<int> &nums, std::vector<int> &copyNums, int start, int end, int &count) {
    // 只有一个数，不存在逆序对
    if (start >= end) {
        return;
    }

    // 将序列划分为对等的两部分
    int mid = start + (end - start) / 2;

    // 递归划分左部分
    mergeSort(nums, copyNums, start, mid, count);
    // 递归划分右部分
    mergeSort(nums, copyNums, mid + 1, end, count);

    // 优化2：如果数组的这个子区间本身有序，无需合并
    if (nums[mid] <= nums[mid + 1]) {
        return;
    }


    // 划分结束后，实行线性合并操作

    // 定义两区间的指针i和j
    // 分别指向两区间的第一个数
    int i = start, j = mid + 1;

    // 计数器
    int k = 0;

    // 两指针都未结束遍历前
    while (i <= mid && j <= end) {
        // 比较指针i指向的数与指向j指向的数，
        // 将较小的数放入临时数组copyNums中
        if (nums[j] < nums[i]) {
            copyNums[k++] = nums[j++];
            // 后一子序的数小于前一子序产生逆序对，
            // 计算逆序对为前一子序i及i后数的个数
            count += (mid - i + 1);
        } else {
            copyNums[k++] = nums[i++];
        }
    }

    // 如果j指针提前结束，
    // 将i指针对应区间剩下的数依次放入临时数组
    while (i <= mid) {
        copyNums[k++] = nums[i++];
    }

    // 如果i指针提前结束，
    // 将j指针对应区间剩下的数依次放入临时数组
    while (j <= end) {
        copyNums[k++] = nums[j++];
    }

    // 每次计算当前合并子序列的大小，
    // 将临时数组内已经排序好的数放回原数组对应部分
    int len = end - start + 1;
    for (int i = 0; i < len; i++) {
        // 注意索引的对应
        nums[start + i] = copyNums[i];
    }
}


