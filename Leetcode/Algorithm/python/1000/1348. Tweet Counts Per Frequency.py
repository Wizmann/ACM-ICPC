# https://leetcode.com/problems/tweet-counts-per-frequency/

INF = 10 ** 10

from collections import defaultdict

class TweetCounts:

    def __init__(self):
        self.d = defaultdict(list)

    def recordTweet(self, tweetName, time):
        self.d[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq, tweetName, startTime, endTime):
        f = {'minute': 60, 'hour': 60 * 60, 'day': 60 * 60 * 24}[freq]
        self.d[tweetName].sort()
        
        m = (endTime - startTime + 1 + f - 1) // f
        res = [0 for i in range(m)]
        l, r = startTime, startTime + f
        idx, ptr = 0, 0
        while idx < len(self.d[tweetName]):
            cur = self.d[tweetName][idx]
            if cur < l:
                idx += 1
                continue
            if cur >= r:
                ptr = max(ptr + 1, (cur - startTime) // f)
                l = startTime + ptr * f
                r = l + f
            elif cur > endTime:
                break
            else:
                res[ptr] += 1
                idx += 1

        return res
