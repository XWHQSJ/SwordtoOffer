//
// Created by Wanhui on 2/29/20.
//

#include <cassert>
#include <climits>
#include "MaxSubArray.h"

int Solution42::maxSubArray(std::vector<int> &nums) {
    assert(!nums.empty());

    int res = INT_MIN;
    int sum = 0;

    // 遍历数组
    for(int i = 0; i < nums.size(); i++){
        // 当sum小于0时，就从下一个数重新开始
        // 同时更新每次叠加的最大值
        if(sum <= 0){
            sum = nums[i];
        }else{
            // 和大于0时
            sum += nums[i];
        }

        // 不断更新子串的最大值
        if(sum > res){
            res = sum;
        }
    }

    return res;
}

int Solution42::maxSubArray2(std::vector<int> &nums) {


    return 0;
}
