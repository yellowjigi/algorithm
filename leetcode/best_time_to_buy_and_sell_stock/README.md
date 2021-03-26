## Brief Description

### brute_force.cpp

* This is a *Time Limit Exceeded (TLE)* version.
* The most naive and intuitive method.
* Search every possible case for the maximum profit using nested `for` loops.

### dp_style.cpp

* An advanced one-pass method.
* `max_profit` can always be calculated as `max(max_profit, prices[i] - min_price)`.
	* Update `max_profit` if `prices[i] - min_price` is greater than it.
* `min_price` can always be calculated as `min(min_price, prices[i])`.
	* Update `min_price` if `prices[i]` is less than it.

### dp_style_2.cpp

* Another version of **dp_style.cpp**.
* It slightly modifies the implementation using `if` statements to (maybe) reduce the total number of computations.