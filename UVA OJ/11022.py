#python3

def kmp(s):
    n = len(s)
    kmp_next = [-1 for i in range(n + 1)]

    pre = -1
    suf = 0
    while pre < n and suf < n:
        if pre == -1 or s[pre] == s[suf]:
            pre += 1
            suf += 1
            kmp_next[suf] = pre
        else:
            pre = kmp_next[pre]
    return kmp_next

d = {}

def solve(s):
    if s in d:
        return d[s]
    n = len(s)
    dp = list(range(1, n + 1))

    for i in range(n):
        nxt = kmp(s[i:])
        m = len(s[i:])
        pre = 0 if i == 0 else dp[i - 1]
        # print(s[i:], nxt)
        for j, num in enumerate(nxt[1:]):
            # print(num, j)
            dp[i + j] = min(dp[i + j], pre + j + 1)
            if num and (j + 1) % (j + 1 - num) == 0:
                u = j + 1 - num
                loop = s[i: i + u]
                v = solve(loop)
                # v = u
                dp[i + j] = min(dp[i + j], pre + v)
        # print(dp)
    d[s] = dp[-1]
    # print(s, d[s])
    return d[s]

while True:
    s = input().strip()
    if s == '*':
        break
    print(solve(s))


'''
^^^TEST^^^
ABBAB
*
------
4
$$$TEST$$$

^^^TEST^^^
BABBABABBABBA
*
------
6
$$$TEST$$$

BABBABABBABBA
^^^^TEST^^^
PRATTATTATTIC
GGGGGGGGG
PRIME
BABBABABBABBA
ARPARPARPARPAR
*
------
6
1
5
6
5
$$$$TEST$$$$
'''


