## Brief Description

### stack.cpp

* Scanning the given string `s`, if `'('` is encountered, push the index of it to `stack`; otherwise, if `')'` is encountered, pop one from `stack` if it's not empty and the top element indicates `'('`.
* After scanning all of the characters in `s`, we remove the characters indicated by the elements still remaining in `stack`. Because the stack is Last-In-First-Out (LIFO), we can remove them using the `string::erase` function in a trivial manner. (Unless we remove the characters from the end of the string like this, we might need to adjust the index of the next target character each time a character is removed.)