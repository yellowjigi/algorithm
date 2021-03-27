## TODO

* Insert some figures for the descriptions.

## Brief Description

### contiguous_blocks.cpp

* The most intuitive method.
* First find the point for `buy` that is the local minimum price (i.e., a valley).
* Then find the point for `sell` that is the local maximum price (i.e., a peak).
* For every pair of `buy` and `sell` found, add `sell - buy` to `max_profit`.
* Return `max_profit`.

### greedy.cpp

* Need more than intuition.
* Walking through `prices`, if and only if `prices[i + 1] - prices[i]` is positive, add it to `max_profit`.
* Return `max_profit`.

### dp_style.cpp

* The most complex version.
* In this approach, think of it as a situation where an individual decides to buy or sell on each day, rather than think of it as just a chart to find a pattern from.
* The individual can choose one of three **actions** on each day: buy, sell, or doing nothing; and can be in one of two **states**: having a stock or not.
* Start from the goal. That is, on the last day, she will be in a state **not having a stock** with the maximum possible profit.
	* To achieve this, on the last day she needs to either *sell the stock if she bought one before*, or *do nothing if she does not have one*.
	* Then, on the last day, by doing which action will she get the maximum profit? I mean, by selling the stock or by doing nothing? Since we don't know it, we need to calculate it by dividing the problem into two cases based on the state and keeping track of both of them throughout the entire period: 1) the maximum possible profit with NO stock in hand (updated in `mp_ns`) on the `i`th day and 2) the maximum possible profit with a stock in hand (updated in `mp_s`) on the `i`th day.
	* In `max(mp_ns, mp_s + prices[i])` of 1), `mp_ns` indicates **doing nothing** and `mp_s + prices[i]` indicates **selling** on the `i`th day.
	* In `max(mp_s, mp_ns - prices[i])` of 2), `mp_s` indicates **doing nothing** and `mp_ns - prices[i]` indicates **buying** on the `i`th day.
	* Return `mp_ns` (i.e., the maximum possible profit on the last day).