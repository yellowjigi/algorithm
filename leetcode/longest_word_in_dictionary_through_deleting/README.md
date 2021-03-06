## Brief Description

### sort_and_find.cpp

* It's a two-step "sort and find" strategy with low performance.
* Sort `dictionary` using a custom comparing function `comp`.
	* It sorts `dictionary` in longer-string-first order where in each set of the strings of the same length they are sorted in alphabetical order.
	* For example, ["a", "aa", "ab", "ac", "abc"] would become ["abc", "aa", "ab", "ac", "a"].
* For each element in sorted `dictionary`, if it can be extracted from the given string `s`, then we are done.
	* To achieve this, we just search through `s` for every character of each target string `dictionary[i]`.
	* In case `dictionary[i]` is longer than `s`, we `continue` to the next loop because it is obviously impossible for it to be the answer.
	* If every character of `dictionary[i]` is found from `s`, we assign it to `result` and immediately break out of the loop.
	* This will produce a valid result because `dictionary` has been sorted as mentioned above.