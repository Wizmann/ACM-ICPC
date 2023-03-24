# Palindrome

> A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward. For example, “racecar” and “level” are palindromic words. 

## Dynamic Programming

The DP approach can find the longest palindrome substring in O(n^2) time and space. But usually we'll use [[Palindrome#Manacher|Manacher]] since it has O(n) time/space complexity.

For the **longest palindrome subsequence** problem, [[Dynamic Programming]] is the only approach. We can either take the O(n^2) time/space approach to find out all possible palindrome subsequences, or make it another DP problem, longest common subsequence, which has O(n) time and O(n^2) space.”

### Problems

* [Leetcode 5. Longest Palindromic Substring][1]
* [Leetcode 516. Longest Palindromic Subsequence][2]

## Manacher

### Problems

* [[Luogu-P4555 最长双回文串]]

[1]: https://leetcode.com/problems/longest-palindromic-substring/
[2]: https://leetcode.com/problems/longest-palindromic-subsequence/