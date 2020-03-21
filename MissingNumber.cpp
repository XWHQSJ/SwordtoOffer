//
// Created by Wanhui on 3/21/20.
//

#include "MissingNumber.h"

int Solution53_2::missingNumber(std::vector<int> &nums) {
    if(nums.empty()){
        return -1;
    }

    std::vector<int> count(nums.size() + 1, 0);
    for(int num : nums){
        count[num]++;
    }

    for(int i = 0; i < count.size(); i++){
        if(count[i] == 0){
            return i;
        }
    }

    return -1;
}

int Solution53_2::missingNumber2(std::vector<int> &nums) {
    return 0;
}
