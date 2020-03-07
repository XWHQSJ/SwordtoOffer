//
// Created by Wanhui on 3/7/20.
//

#include "MaxSlidingWindow.h"

std::vector<int> Solution59_1::maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> ans;
    int maxNum = 0;
    for(int small = 0, big = k-1; big < nums.size(); small++, big++){
        maxNum = retMax(nums, small, big);
        ans.push_back(maxNum);
    }

    return ans;
}

int Solution59_1::retMax(std::vector<int> &nums, int small, int big) {
    int maxNum = nums[small];
    for(int i = small; i <= big; i++){
        if(maxNum < nums[i]){
            maxNum = nums[i];
        }
    }
    return maxNum;
}



std::vector<int> Solution59_1::maxSlidingWindow2(std::vector<int> &nums, int k) {


    return std::vector<int>();
}


