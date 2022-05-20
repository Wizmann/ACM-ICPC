#python2
import sys

def z_function(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r and z[i - l] < r - i + 1:
            z[i] = z[i - l]
        else:
            z[i] = max(0, r - i + 1)
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z

for line in sys.stdin:
    line = line.strip()
    s = line[::-1] + '#' + line
    n = len(line)
    z = z_function(s)
    maxi = 0
    # print(s)
    for i in range(n + 1, len(s)):
        if z[i] + i == len(s):
            maxi = max(maxi, z[i])
    res = line + line[:n - maxi][::-1]
    print(res)

'''

^^^TEST^^^
baabbbabaa
------
baabbbabaababbbaab
$$$TEST$$$

^^^TEST^^^
xy
fuck
a
ababab
abcba
abcBA
qwertyuiop
-----
xyx
fuckcuf
a
abababa
abcba
abcBABcba
qwertyuiopoiuytrewq
$$$TEST$$$

^^^TEST^^^
aaaa
abba
amanaplanacanal
xyz
Aa
AA
ABB
xyzx
------
aaaa
abba
amanaplanacanalpanama
xyzyx
AaA
AA
ABBA
xyzxzyx
$$$TEST$$$

'''


