## Brief Description

### dp.cpp

* `dp[k][i]` denotes a maximum possible profit up to the `i`th day with (at most) `k` transactions.
* First see the step-by-step logic for `k = 2`: [best_time_to_buy_and_sell_stock_iii](https://github.com/yellowjigi/algorithm/tree/main/leetcode/best_time_to_buy_and_sell_stock_iii).
* The logic is the same as the one for `k = 2` above except that:
	* We can implement the concept of "no limit in `k`" by removing the first dimension from `dp`. As a result, `dp[k][i]` becomes `dp[i]` which now denotes a maximum possible profit up to the `i`th day with as many transactions as possible.
	* `- fee` is added in updating `max_balance_after_buying` because now an extra fee is charged per transaction. Here, we apply the `- fee` part when we buy rather than when we sell.
* Return `dp[prices.size() - 1]` which indicates the maximum possible profit up to the last day with as many transactions as possible.

### dp_space_optimized.cpp

* This is a version with improved space complexity (i.e., O(1)).
* Remove the vector `dp` and replace `dp[i - 1]` and `dp[i]` with `yesterday` and `today`, respectively.
* Note that we return `yesterday` instead of `today` for generalization. (Think of the case where `prices.size()` is `1`. In this case, returning `today` will become a problem because the `for` loop is not entered and `today` is not assigned any value.)