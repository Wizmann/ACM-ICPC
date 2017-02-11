import sys
import re

n = int(raw_input())
res = []
for i in xrange(n):
    g = re.findall(r"https?:\/\/(?:ww[w|2].)?(.*?)[^a-zA-Z0-9\-\.]", raw_input())
    res += filter(lambda x: x.count('.') >= 1, g)
    
print ';'.join(sorted(set(res)))


