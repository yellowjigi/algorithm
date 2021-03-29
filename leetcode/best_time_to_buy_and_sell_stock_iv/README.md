## TODO

* Implement an optimized version of DP.

## Brief Description

### dp.cpp

* `dp[k][i]` denotes a maximum possible profit up to the `i`th day with (at most) `k` transactions.
* First see the step-by-step logic for `k = 2`: [best_time_to_buy_and_sell_stock_iii](https://github.com/yellowjigi/algorithm/tree/main/leetcode/best_time_to_buy_and_sell_stock_iii).
* For bigger `k`, we can generalize it simply with a `for` loop to iterate through every `k`.
* Return `dp[k][prices.size() - 1]` which indicates the maximum possible profit up to the last day with (at most) `k` transactions.