#!/bin/python

import sys

def sherlockAndAnagrams(s):
    n = len(s)
    prefix = [ [0 for i in xrange(n)] for j in xrange(26) ]
    
    for i in xrange(n):
        c = ord(s[i]) - ord('a')
        prefix[c][i] += 1
        
        if i > 0:
            for j in xrange(26):
                prefix[j][i] += prefix[j][i - 1]
    
    ans = 0
    for i in xrange(n):
        for j in xrange(i + 1, n):
            for k in xrange(n):
                if i + k >= n or j + k >= n:
                    continue
                flag = True
                
                for l in xrange(26):
                    a = prefix[l][i + k] - (0 if i == 0 else prefix[l][i - 1])
                    b = prefix[l][j + k] - (0 if j == 0 else prefix[l][j - 1])
                    
                    if a != b:
                        flag = False
                        break
                if flag:
                    ans += 1
    return ans
    
q = int(raw_input().strip())
for a0 in xrange(q):
    s = raw_input().strip()
    result = sherlockAndAnagrams(s)
    print(result)

