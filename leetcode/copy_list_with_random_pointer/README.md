## Brief Description

### unordered_map.cpp

* `randoms` is a vector where `randoms[i]` indicates an index of the node pointed to by `random` of the *i*th node. If it is `NULL`, `-1` is stored. (E.g., for *Example 1* from the test case, this vector is constructed as { -1, 0, 4, 2, 0 })
* During the first pass, each { address, index } of the original nodes is stored in the unordered map `hash_table` and new nodes are constructed and pushed back to the vector `new_nodes` so that we can access each node by its index later.
* During the second pass, the vector `randoms` is populated as defined above. Here, it maps the address of a node (pointed to by `random`) to an index. Indices can be retrieved by doing `hash_table[node->random]` since { address, index } of each node has been stored in the unordered map `hash_table`.
* During the last pass, the copy is completed by assigning `next` and `random` of each new node. We can now assign `random` using the indices of the nodes as they are stored in a vector.
