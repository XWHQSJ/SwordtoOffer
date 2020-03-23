//
// Created by Wanhui on 3/22/20.
//

#include "ReversePairs.h"

int Solution51::reversePairs(std::vector<int> &nums) {
    if(nums.empty()){
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] > nums[j]){
                ans++;
            }
        }
    }

    return ans;
}
