## TODO

* Implement it with a dynamic programming (DP) approach.

## Brief Description

### just_math.cpp

* *Check-continue-stop-resume* strategy
* *Check*: check if the difference from the current index (`nums[i] - nums[i - 1]` is equal to the one from the previous index (`diff`).
* *Continue*: if the differences are the same, increment `count` and continue checking until the differences are not the same.
* *Stop*: if the differences are not the same, we stop to calculate the number of slices of the last arithmetic subarray and add it to `result`.
* By the formula of the sum of an arithmetic sequence, the total number of arithmetic slices of an arithmetic (sub)array which consists of *n* elements is calculated as follows:
<p align="center">
  <img src="https://latex.codecogs.com/svg.latex?\frac{(n-1)(n-2)}{2}">
</p>

* *Resume*: reset `count` to `2` and advance the `for` loop to repeat the cycle.
