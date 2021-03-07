## Brief Description

### recursive.cpp

* Important points
	* The recursive function `parenth` calculates and returns a score of *one* pair of parentheses where the index of the opening one is given as `i`.
	* If there are one or more pairs of parentheses inside the current pair, all of them are calculated separately by recursive calls to `parenth` and added to `sum` within the `while` loop.
	* After each call to `parenth`, `i` points to the closing parenthesis. It is then incremented (`++i`) to examine if there is another pair to add.
	* `i`, indicating the current position in `S`, is passed to `parenth` *by reference* so that the updated value of it can be kept across the recursive calls.
