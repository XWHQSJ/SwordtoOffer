//
// Created by Wanhui on 3/23/20.
//

#include "TwoSum60.h"

std::vector<double> Solution60::twoSum(int n) {
    if (n < 0) {
        return {};
    }

    std::vector<double> dp(n * 6 + 1, 0.0);
    for (int i = 1; i <= 6; i++) {
        dp[i] = 1.0 / 6.0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = i * 6; j >= i; j--) {
            dp[j] = 0;
            for (int k = j-1; k >= i-1 && k >= j-6; k--) {
                dp[j] += dp[k] * 1.0 / 6.0;
            }
        }
    }

    std::vector<double> ans(dp.begin() + n, dp.end());

    return ans;
}
