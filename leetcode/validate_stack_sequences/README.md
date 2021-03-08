## Brief Description

### just_try_it.cpp

* To validate the given stack sequences, just try yourself as given.
* While pushing the items of `pushed` to `stack` in turn, whenever the value of `stack.top()` is equal to `popped[j]`, pop it from `stack` and do `++j`.
* After walking through all the elements in `pushed`, if `stack` is empty, return `true`; otherwise, return `false`.