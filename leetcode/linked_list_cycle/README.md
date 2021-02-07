## TODO
1. Add another version where the input data are intact but space complexity is O(n)
2. Add another version where the input data are intact and space complexity is still O(1)
3. Add versions with comments respectively

## Pros & cons of each algorithm

### modifying_input.c

#### Pros

* The space complexity is O(1) for the `hasCycle` function because there is always no memory allocation regardless of the number of the input nodes.

#### Cons

* It modifies the input data replacing all the values of `val` of the `ListNode` objects with `-100001`, as one of the given constraints from the problem limits the range of `val` such that `-10⁵ <= Node.val <= 10⁵`.
