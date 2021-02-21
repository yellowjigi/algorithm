## Brief Description

### arithmetic.cpp

* Arithmetic division operations are used.

### bitwise.cpp

* Think of the input `num` as a binary number.
* If the intermediate result is even, shift `num` 1 bit to the right; otherwise, decrement it. In either case, increment `count` which was initialized to `0`.
* Whether the intermediate result is even or not is checked using the bitwise AND (`&`) operation with `1`.
* If `num` becomes `0`, return the `count`.