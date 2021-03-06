## Brief Description

### sort_and_compare.cpp & sort_and_find.cpp

#### Common features

* Both of them employ two-step "sort and find" strategies with relatively low performance.
* Sort `dictionary` using a custom comparing function `comp`.
	* It sorts `dictionary` in longer-string-first order where in each set of the strings of the same length they are sorted in alphabetical order.
	* For example, ["a", "aa", "ab", "ac", "abc"] would become ["abc", "aa", "ab", "ac", "a"].
* For each element in sorted `dictionary`, if it can be extracted from the given string `s`, then we are done.
	* To achieve this, we just search through `s` for every character of each target string `dictionary[i]`.
	* In case `dictionary[i]` is longer than `s`, we `continue` to the next loop because it is obviously impossible for it to be the answer.
	* If every character of `dictionary[i]` is found from `s`, we return it immediately breaking out of the loop.
	* This will produce a valid result because `dictionary` has been sorted as mentioned above.

#### Differences

* When searching `s` for the characters of `dictionary[i]`, **sort_and_compare.cpp** compares the characters index by index whereas **sort_and_find.cpp** utilizes the `string::find` function.
