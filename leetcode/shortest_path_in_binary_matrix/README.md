## TODO

* Calculate the time complexities of both of the versions and compare them.
* Optimize the current algorithm or implement another.
* Add more details in the description.

## Brief Description

### bfs.cpp

* It implements Breadth First Search (BFS) approach using a queue.
* `depth` indicates the "length" in the question.
* It modifies the value to `-1` on the grid each time it inspects an item from the queue (`q.front()`) to avoid later considering the point where we have already been.
* This is an *Accepted* version. See below the explanation of the *Time Limit Exceeded (TLE)* version.

### bfs_tle.cpp

* This is a *Time Limit Exceeded (TLE)* version.
* Compared to the *Accepted* version, this one allows the same point (`pair<int, int>` objects) to be pushed to the queue multiple times, which will require more computation time.
* This version does not produce a *Wrong Answer* though.
* This version can be used when tracing the paths is also required, as it knows all the variants of the paths of the same length during the calculations.
* However, since only the length is required in this question, it is okay to assign the point to `-1` immediately after it is pushed to the queue. This way, points are guaranteed to be pushed to the queue only one time.