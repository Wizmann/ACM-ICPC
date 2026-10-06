MAX_PACKAGES = (10 ** 5) + 123
INF = 10 ** 100
MOD = (10 ** 9) + 7

class Solution(object):
    def minWastedSpace(self, packages, boxes):
        pre_packcnt = [0 for i in xrange(MAX_PACKAGES)]
        pre_packval = [0 for i in xrange(MAX_PACKAGES)]

        for pack in packages:
            pre_packcnt[pack] += 1
            pre_packval[pack] += pack
            
        for i in xrange(1, MAX_PACKAGES):
            pre_packcnt[i] += pre_packcnt[i - 1]
            pre_packval[i] += pre_packval[i - 1]
            
        max_packet = max(packages)
        
        mini = INF
        for box in boxes:
            box.sort()
            tot = 0
            if max(box) < max_packet:
                continue
            for i, item in enumerate(box):
                pre_item = 0 if i == 0 else box[i - 1]
                cnt = pre_packcnt[item] - pre_packcnt[pre_item]
                val = pre_packval[item] - pre_packval[pre_item]
                # print pre_item, item, cnt, val
                tot += item * cnt - val
            mini = min(mini, tot)
        return -1 if mini >= INF else (mini % MOD)
