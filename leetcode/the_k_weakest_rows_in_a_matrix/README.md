## TODO

* Implement a binary-search version to reduce time to find the first civilian position.

## Brief Description

### pair_stable_sort.cpp

1. Find the first occurrence of civilians (that is equal to the number of soldiers) for each row of `mat`.
2. Save both the index of the row and the number of the soldiers in the `strength` vector as pairs.
3. Repeat it over every row.
4. Sort `strength` by the `second` elements of the pairs (i.e., the number of soldiers) using the custom comparing function `comp`. `stable_sort` function is used to preserve the order of equivalents, as the question states that if two rows have the same number of soldiers the preceding one is weaker.
5. Return the `result` vector containing the first `k` elements of the indices of the rows which are saved as the `first` element of the pairs in `strength`.