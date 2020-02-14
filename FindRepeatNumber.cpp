//
// Created by Wanhui on 2/12/20.
//

#include "FindRepeatNumber.h"
#include "QuadSort.h"
#include <unordered_map>
#include <iostream>

int Solution03::findRepeatNumber(std::vector<int> &nums) {
    int n = 0;

    int i;
    // 找到数组中最大的数，
    // 该步骤可省略，可将存储数组的大小设置为最大值
    for(i = 0; i < nums.size(); i++){
        if(n < nums[i]){
            n = nums[i];
        }
    }

    std::vector<int> numcount(n+1);

    for(i = 0; i < nums.size(); i++){
        numcount[nums[i]]++;

        if(numcount[nums[i]] > 1) {
            return nums[i];
        }
    }

    return 0;
}

int Solution03::findRepeatNumber2(std::vector<int> &nums) {
    std::unordered_map<int, int> hash(nums.size());

    for(int& num : nums){
        hash[num]++;

        if(hash[num] > 1){
            return num;
        }
    }

    return 0;
}

int Solution03::findRepeatNumber3(std::vector<int>& nums) {

    // using quadsort algorithm ==> sort time only O(n)
    // convert std::vector<int> to int *
    // just use std::vector function data()
    quadsort(nums.data(), nums.size(), sizeof(int), cmp_int);

    int c = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(c == nums[i]){
            return c;
        } else {
            c = nums[i];
        }
    }

    return 0;
}
