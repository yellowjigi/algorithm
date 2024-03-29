## Brief Description

### find_unique_alphabet.cpp

* Record the count of each number in the vector `count` using alphabets that uniquely belong to it.
	* For example, `'z'` only belongs to `"zero"`, `'w'` only belongs to `"two"`, and so on.
	* To make things simple, we first inspect the even numbers and then inspect the odd numbers. This way, for example, `'o'` can be thought of as a character that uniquely belongs to `"one"` without any problem because at this point every number other than `"one"` that contains `'o'` has already been inspected (that is, `"zero"`, `"two"`, and `"four"`).
* Print the digits according to the numbers stored in `count`.
	* Of course they first need to be converted to the corresponding ASCII representations, by doing `'0' + i`.