## Brief Description

### two_pointers.cpp

* This is an *Accepted* version, which people call the "two pointers" method.
* Starting with `left` and `right` pointing to `0` and `height.size() - 1` respectively, we move one with a smaller height toward the other by each `while` loop until `left == right`, updating `max_area`.
* The reason why we move the one with smaller height is because otherwise there is obviously no chance to get a bigger area as the width is always getting smaller and the height remains the same.

### naive_tle.cpp

* This is a *Time Limit Exceeded (TLE)* version.
* It uses a typical brute force approach with two nested `for` loops and examine every case.

### one_pointer_tle.cpp

* This is a *Time Limit Exceeded (TLE)* version.
* Compared to the "two pointers" approach above, it moves one reference pointer, marked as `i` of the outer `for` loop.
* Moving this pointer, we seek the biggest possible area `i` can make with the heights it indicates. The width is determined with the help of another pointer `j` as it moves left and right to `i`. `j` is selected to calculate the width only when the height it indicates is higher than that of `i`.