from collections import defaultdict

class Solution(object):
    def largestWordCount(self, messages, senders):
        d = defaultdict(int)
        
        for (msg, sender) in zip(messages, senders):
            cnt = len(msg.split())
            d[sender] += cnt
        return sorted(d.items(), key=lambda (name, cnt): (cnt, name), reverse=True)[0][0]
