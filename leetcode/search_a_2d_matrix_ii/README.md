## Brief Description

### binary_search.cpp

* Fast search each row of `matrix` for `target` using the `binary_search` function.
* Time complexity: O(MlogN) where M denotes `matrix.size()`, the number of rows, and N denotes `matrix[0].size()`, the number of columns.

### top_right.cpp

* Starting from the top-right corner of `matrix`, do one of the following:
	* If the number is less than `target`, move one row downward as all other numbers of the row are also less than it;
	* if the number is greater than `target`, move one column leftward as all other numbers of the column are also less than it;
	* if the number is equal to `target`, return `true` as we found it;
	* if either the row or column index is out of the range of `matrix`, return `false` as we could not find it.
* Time complexity: O(M + N) where M and N denote the same as above.