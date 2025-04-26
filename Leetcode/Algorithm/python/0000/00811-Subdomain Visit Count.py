from collections import defaultdict
class Solution(object):
    def subdomainVisits(self, cpdomains):
        d = defaultdict(int)
        for cpdom in cpdomains:
            cnt, dom = cpdom.split(' ')
            dom = dom.split('.')
            cnt = int(cnt)
            m = len(dom)
            for i in xrange(m):
                subdom = '.'.join(dom[i:])
                d[subdom] += cnt
        return map(lambda (subdom, cnt): "%d %s" % (cnt, subdom), d.items())

assert set(Solution().subdomainVisits(["9001 discuss.leetcode.com"])) == set(["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"])
assert set(Solution().subdomainVisits(["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"])) == set(["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"])
