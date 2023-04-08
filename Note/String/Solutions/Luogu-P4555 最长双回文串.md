# Luogu P4555 最长双回文串


Tags: #String #Palindrome #DP

* Related Topics:
  * [[Palindrome]]
  * [[Dynamic Programming]]
* Problem: [Link][1]
* Code: [Luogu P4555][2]


## Description

Given a string `S` of length N, please find a substring `T` of `S` that composed by `X` and `Y` (i.e. T = X + Y) that both `X` and `Y` are palindromes.

For example, string `baacaabbacabb` has the longest substring `aacaabbacabb` which is composed by two palinedrome `aacaa` and `bbacabb`.

## Solution

The problem could be a simple [[Dynamic Programming]] problem if we can find the the longest palindrome begin with or end with specific charachter.

With [[Palindrome#Manacher|Manacher]] algorithm, we can find the longest palindrome substring from every "center" character of the palindrome. And we can use that info to deduce the possible (may not the longest) palindromes centered with the character, and mark the maximal/minimal length of the palindromes start/end with each characters.

When looking for the longest palindrome, we need to account for both odd and even lengths. For instance, `aaaaa` is a palindrome of length 5, but it can also be reduced to palindromes of length 3 `aaa` and 1 `a`. Similarly, it can be reduced to palindromes of length 4 `aaaa` and 2 `aa`.

[1]: https://www.luogu.com.cn/problem/P4555
[2]: https://github.com/Wizmann/ACM-ICPC/blob/master/Luogu/P4555.cc