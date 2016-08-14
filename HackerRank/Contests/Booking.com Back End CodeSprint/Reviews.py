import sys
import time
import datetime
import re

def timestamp2int(ts):
    return int(datetime.datetime.fromtimestamp(ts).strftime("%Y%m%d"))
    
def get_score(ts, review):
    score = 0
    if 20160615 <= ts < 20160715:
        score += 20
    else:
        score += 10
        
    if len(review) >= 100:
        score += 20
    else:
        score += 10
    return score
    
assert timestamp2int(1467720000) == 20160705

(n, m) = map(int, raw_input().split())
passions = [raw_input().lower() for i in xrange(n)]
passions_s = set(passions)

d = {}

for i in xrange(m):
    (idx, ts) = map(int, raw_input().split())
    ts = timestamp2int(ts)
    
    review = raw_input().lower()
    score = get_score(ts, review)
    
    if idx not in d:
        d[idx] = {}
        
    for item in passions:
        if item in review:
            d[idx][item] = d[idx].get(item, 0) + score
    
for passion in passions:
    ans = 0
    idx = -1
    for key, value in d.items():
        s = value.get(passion, -1)
        if s > ans:
            ans = s
            idx = key
        elif s == ans and idx > key:
            idx = key
    print idx
    
