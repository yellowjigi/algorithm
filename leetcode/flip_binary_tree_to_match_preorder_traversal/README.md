## Brief Description

### preorder_recursive.cpp

* Three important strategies to note:
	1. `preorder` returns count of the subtree including the `root` passed to it.
	2. This is an optimistic approach. That is, even though in the future it might turn out that it's impossible, we flip if it seems to work for now. If at some point in the future it turns out impossible, `preorder` immediately returns and sends a signal `-1` to the callers recursively.
	3. `flipped_nodes`, the list of the values we are supposed to return, is passed as reference to the recursive calls to `preorder` so that it can be easily updated across the recursive calls.
* Inserting the value of the node into `flipped_nodes` only takes place if both of the `left` and `right` children exist and it seems to work for now (more specifically, with the right next value `voyage[i + 1]` for now) to flip.
	* If no children exist or only one exists, flip is not needed because it's a *preorder* traversal.
* Every call to `preorder` returns the count of the nodes of the subtree so that the next index in `voyage` can be easily calculated.
* **So when is the moment it turns out impossible?** That's when the condition `root->val != voyage[i]` is met. If the root node has a different value, there is nothing we can do.