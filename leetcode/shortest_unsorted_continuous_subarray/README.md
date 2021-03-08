## Brief Description

### sort_and_compare.cpp

* Copy the original vector `nums` to `nums_copy` and sort it.
* Now compare `nums` and sorted `nums_copy` element by element.
* If any difference is found, return the number of elements to be sorted (which is calculated as `j - i + 1`).
* If no difference is found at all (`if (i == nums.size())`), immediately return `0`.