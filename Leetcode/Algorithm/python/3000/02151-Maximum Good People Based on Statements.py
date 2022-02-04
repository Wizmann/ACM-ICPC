class Solution(object):
    def maximumGood(self, statements):
        n = len(statements)
        res = 0
        for i in xrange(1 << n):
            tags = [0 for j in xrange(n)]
            for j in xrange(n):
                is_good = 1 if i & (1 << j) else 0
                tags[j] = is_good
            flag = True
            # print tags
            for j in xrange(n):
                is_good = 1 if i & (1 << j) else 0
                if not is_good:
                    continue

                for k in xrange(n):
                    if statements[j][k] == 2:
                        continue
                    tag = statements[j][k] ^ (is_good ^ 1)
                    # print k, tag

                    if tags[k] != tag:
                        flag = False
                        break
                if not flag:
                    break
            if flag:
                res = max(res, sum(tags))
        return res

'''
^^^^test^^^
[[2,1,2],[1,2,2],[2,0,2]]
------
2
$$$TEST$$$

^^^^test^^^
[[2,0],[0,2]]
------
1
$$$TEST$$$

^^^^test^^^
[[2,0,2,2,0],[2,2,2,1,2],[2,2,2,1,2],[1,2,0,2,2],[1,0,2,1,2]]
------
2
$$$TEST$$$
'''

