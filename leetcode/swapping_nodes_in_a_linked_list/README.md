## Brief Description

### two_pass_pointer.cpp

* During the first pass:
	* Get `count` which indicates the total number of the nodes.
	* Save the value of the `k`th node in `val`.
	* Also save the address of the value of the `k`th node in `valp`.
* During the second pass:
	* Rewind `node` to point to `head`.
	* Advance `node` and decrement `count` until `count` becomes `k`.
	* Now assign `node->val` to the value `valp` points to.
	* Also assign `val` to `node->val`.
	
### two_pass_pointer_clear.cpp

* This is a clear version of **two_pass_pointer.cpp**.