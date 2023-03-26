# Luogu-P5937 ParityGame

Tags: #Disjoint-Set #Satisfiability #Boolean-Function

* Related Topics:
    * [[Disjont_Set]]
* Program: [Link][1]
* Code: [Luogu P5937][2]

## Description

Alice and Bob are playing a game with a sequence of 0s and 1s which is written by Bob.

Alice picks a segment of the sequence (for instance, from the 3rd to the 5th position) and asks Bob if the number of 1s in that segment is odd or even.

Bob answers her question and Alice keeps asking. Alice wants to verify Bob’s answers and identify if there's an incorrect one. An answer is incorrect if there exists a 0-1 sequence that matches all the previous answers but not the current one.

## Solution

> The index of a sequence described below starts from `1`.

We can reformulate this problem as a satifiability problem. Suppose we have a sequence `nums[a...b]` that contains an even number of 1s.

Then we can infer that the sequences `nums[1...a - 1]` and `nums[1...b]` have the same parity, that is, they both contain an even or odd number of `1`s. On the other hand, if `nums[a...b]` contains an odd number of `1`s, then the sequences `nums[1...a - 1]` and `nums[1...b]` have opposite parity.

Let us define `f(x)` as a Boolean function that returns true if and only if `nums[1...x]` contains an odd number of `1`s, and false otherwise. Then we can express the parity relation between two sequences as follows: if `nums[a...b]` has even number of `1`s, then `f(a - 1) = f(b)`; if `nums[a...b]` has odd number of `1`s, then `f(a - 1) = !f(b) && !f(a - 1) = f(b)`.

We can construct a graph with nodes representing all possible values of `f(0...n)` and `!f(0...n)`. If we have a parity relation between two sequences, we add an edge between the corresponding nodes. If there is an edge between `f(x)` and `!f(x)` for some x, then we have a contradiction and the answer must be incorrect."

[1]: https://www.luogu.com.cn/problem/P5937
[2]: https://github.com/Wizmann/ACM-ICPC/blob/master/Luogu/P5937.cc