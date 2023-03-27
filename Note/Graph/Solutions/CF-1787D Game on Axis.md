# CF-1787D Game on Axis

Tags: #Graph-Traversal #DFS #Counting
* Related Topics:
    * [[Graph Traversal]]
    * [[DFS]]
* Program: [Link][1]
* Code: [CF-1787D][2]

## Description

There are `n` points `1,2,…,n`, each point `i` has a number `a[i]` on it.  (`1≤n≤2⋅10^5`)

You're playing a game on them. Initially, you are at point `1`. When you are at point `i`, take following steps:

- If `1≤i≤n`, go to `i+a[i]`,
- Otherwise, the game ends.

Before the game begins, you can choose two integers `x` and `y` satisfying `1≤x≤n`, `−n≤y≤n` and replace `a_x` with `y` (set `a_x:=y`). Find the number of distinct pairs `(x,y)` such that the game that you start after making the change ends in a finite number of steps.

Notice that you do not have to satisfy `a[x]≠y`.

## Solution


[1]: https://codeforces.com/contest/1787/problem/D
[2]: https://github.com/Wizmann/ACM-ICPC/blob/master/Codeforces/TypeDB%20Forces%202023/D.py