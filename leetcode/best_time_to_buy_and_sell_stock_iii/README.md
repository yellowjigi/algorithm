## TODO

* Implement an optimized version of DP.

## Brief Description

### dp.cpp

* `dp[k][i]` denotes a maximum possible profit up to the `i`th day with (at most) `k` transactions.
* More specifically, `dp[0]`, `dp[1]`, and `dp[2]` are vectors where
	* `dp[0][i]` indicates a maximum possible profit up to the `i`th day with `0` transaction;
	* `dp[1][i]` indicates a maximum possible profit up to the `i`th day with (at most) `1` transaction; and
	* `dp[2][i]` indicates a maximum possible profit up to the `i`th day with (at most) `2` transactions.
* Build `dp[0]`:
	* It is obvious that every element of `dp[0]` is `0` (as has been already initialized).
* Build `dp[1]`
	* Think of `i` as today and `i - 1` as yesterday.
	* We keep track of `max_balance_after_buying` which indicates the maximum possible balance if we bought a stock until today. Here, `dp[0][i - 1]` indicates that no transaction can take place up to yesterday because it takes place today. (See `- prices[i]` which means we buy it today.)
	* Using `max_balance_after_buying`, we update `dp[1][i]`. If there is an increase in the price today, we want to sell it (`+ prices[i]`). If the profit is greater than the last one (`dp[1][i - 1]`), we update `dp[1][i]`. So, for example, if there is no increase in the price over the entire period, every element will be `0`.
* Build `dp[2]`
	* Same as `dp[1]` except that here we use `dp[1][i - 1]` instead of `dp[0][i - 1]` to keep track of `max_balance_after_buying` because we can do at most `2` transactions now.
* Return `dp[2][prices.size() - 1]` which indicates the maximum possible profit up to the last day with (at most) 2 transactions.