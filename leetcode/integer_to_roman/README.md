## Brief Description

### unordered_map_forwards.cpp

* Simple method that converts integers to the Roman numerals digit by digit forwards.
* To convert the integers one by one to the Roman numerals, use a divisor `d` to get a quotient `q` and a remainder `r` during each `while` loop. Starting from `1000` (because the constraints in the question indicate `num <= 3999`), `d` is divided by `10` at the end of each `while` loop and the loop terminates when `d` becomes `0`.
* There are some unusual cases that should be treated specially: when the digit is either `4` or `9`. Corresponding Roman numerals can be constructed easily though with the information saved earlier, such as `d` and `r`.
* Except these cases, `um[d]` which indicates either `I`, `X`, `C`, or `M` is repeated for `q` times. If `q` is greater than or equal to `5`, then `um[d * 5]` which indicates either `V`, `L`, or `D` is put first and `um[d]` is repeated for `q - 5` times.
* The corresponding units of the Roman numeral system can be easily retrieved with `unordered_map`.