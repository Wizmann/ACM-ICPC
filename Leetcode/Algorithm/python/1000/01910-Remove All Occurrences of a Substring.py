def kmp(s):
    n = len(s)
    kmp_next = [-1 for i in xrange(n + 1)]

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

class Solution(object):
    def removeOccurrences(self, s, part):
        kmp_next = kmp(part)
        dp = [0]
        st = ['^']
        m = len(part)
        print kmp_next
        for c in s:
            cur = dp[-1]
            while cur != -1 and c != part[cur]:
                cur = kmp_next[cur]
            cur += 1
            dp.append(cur)
            st.append(c)

            if cur == m:
                dp = dp[:-m]
                st = st[:-m]
        return ''.join(st[1:])

# print Solution().removeOccurrences("daabcbaabcbc", "abc")
