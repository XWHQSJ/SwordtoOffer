//
// Created by Wanhui on 3/21/20.
//

#include "MissingNumber.h"

int Solution53_2::missingNumber(std::vector<int> &nums) {
    if (nums.empty()) {
        return -1;
    }

    // 定义次数数组（桶）
    std::vector<int> count(nums.size() + 1, 0);

    // 将数出现的次数存放在数对应的索引上
    for (int num : nums) {
        count[num]++;
    }

    // 遍历次数数组，如果次数为0表示该索引对应的数缺失
    for (int i = 0; i < count.size(); i++) {
        if (count[i] == 0) {
            return i;
        }
    }

    return -1;
}

int Solution53_2::missingNumber2(std::vector<int> &nums) {
    if(nums.empty()){
        return -1;
    }



    return 0;
}

int Solution53_2::missingNumber3(std::vector<int> &nums) {
    if(nums.empty()){
        return -1;
    }

    // n个数
    int n = nums.size() + 1;

    // 计算n个数的和
    int sum1 = (n * (n-1))/2;

    // 计算数组中所有数的和
    int sum2 = 0;
    for(int num : nums){
        sum2 += num;
    }

    // 返回差
    return (sum1 - sum2);
}
