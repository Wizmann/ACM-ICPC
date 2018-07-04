'''$$$
[Description]
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

[Tag]
string, implementation

[Difficulty]
1

[Url]
https://leetcode.com/problems/buddy-strings/description/
$$$'''

class Solution(object):
    def buddyStrings(self, A, B):
        if len(A) != len(B):
            return False
        n = len(A)
        ps = []
        for i in xrange(n):
            if A[i] != B[i]:
                ps.append((A[i], B[i]))
        if not ps and len(set(A)) < len(A):
            return True
        if len(ps) != 2:
            return False
        if ps[0] != ps[1][::-1]:
            return False
        return True
