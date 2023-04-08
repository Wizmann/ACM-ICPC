# Tree Diameter

> Tree diameter is defined as the number of nodes on the longest path between two leaf nodes in the tree.

Tags: #BFS #DFS #DP #Tree
* Related Topics:
    * [[DFS]]
    * [[BFS]]
    * [[Dynamic Programming]]

## Approach

* Start with any node as the root and use [[DFS]] to find the farthest leaf node from it. Then make this leaf node the new root and use [[DFS]] again to find the farthest leaf node from it. The tree diameter is the distance between these two nodes.

* Use [[Topological Sort]] to remove the leaf nodes layer by layer until only one or two nodes remain. These nodes are the "center" of the tree. The tree diameter is the longest path that passes through the "center".


## Problems

* [AtCoder ABC221 F - Diameter set][1]
* [Leetcode 2603. Collect Coins in a Tree][2]

[1]: https://atcoder.jp/contests/abc221/tasks/abc221_f
[2]: https://leetcode.com/problems/collect-coins-in-a-tree/