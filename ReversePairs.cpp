//
// Created by Wanhui on 3/22/20.
//

#include "ReversePairs.h"

int Solution51::reversePairs(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    std::vector<int> copyNums(nums.size(), 0);

    int count = 0;
    mergeSort(nums, copyNums, 0, nums.size() - 1, count);

    return count;
}

void Solution51::mergeSort(std::vector<int> &nums, std::vector<int> &copyNums, int start, int end, int &count) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(nums, copyNums, start, mid, count);
    mergeSort(nums, copyNums, mid + 1, end, count);

    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (nums[j] < nums[i]) {
            copyNums[k++] = nums[j++];
            count += (mid - i + 1);
        } else {
            copyNums[k++] = nums[i++];
        }
    }

    if (i <= mid) {
        std::copy(nums.begin() + i, nums.begin() + mid + 1, copyNums.begin() + k);
    }

    if (j <= end) {
        std::copy(nums.begin() + j, nums.begin() + end + 1, copyNums.begin() + k);
    }

    std::copy(copyNums.begin() + start, copyNums.begin() + end + 1, nums.begin() + start);
}


