## Brief Description

### recursive.cpp

1. The `letterCasePermutation` function invokes `perm` which calls itself recursively.
2. Walking through the given string `S`, if the character is a digit, append it to the string instance `s`; otherwise break out of the loop.
3. Check the terminal condition. If the passed string instance `s` has been built completely, append it to the `result` vector and return.
4. Invoke another set of calls recursively with the current character `s[i]` set to uppercase and lowercase respectively. Here, pass `i + 1` for the `pos` parameter in the recursive calls so that the already-scanned part of `S` will not be checked again during the successive calls.