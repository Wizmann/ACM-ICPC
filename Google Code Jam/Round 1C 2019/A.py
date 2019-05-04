import sys
import random
sys.setrecursionlimit(10000)
# s -> p -> r
# 0    1    2

def win(c):
    return (c + 1) % 3

def lose(c):
    return (c - 1 + 3) % 3

def word_to_list(w):
    res = []
    for c in w:
        if c == 's':
            res.append(0)
        elif c == 'p':
            res.append(1)
        elif c == 'r':
            res.append(2)
        else:
            assert False
    return res

def list_to_word(ns):
    ww = 'SPR'
    res = ''
    for num in ns:
        res += ww[num]
    return res

class Solution(object):
    def repeatedSubstringPattern(self, ss):
        if not ss:
            return ''
        ss = ''.join(map(str, ss))
        kmp_next = self.get_kmp_next(ss)
        n = len(ss)
        g = kmp_next[-1]
        if g != 0 and n % (n - g) == 0:
            return ss[:n - g]
        else:
            return ''
    
    def get_kmp_next(self, ss):
        n = len(ss)
        next = [-1 for i in xrange(n + 1)]
        
        pre, suf = -1, 0
        while pre < n and suf < n:
            if pre == -1 or ss[pre] == ss[suf]:
                pre += 1
                suf += 1
                next[suf] = pre
            else:
                pre = next[pre]
        return next
        

def dfs(ws, cur, depth, roll):
    if depth > 1000:
        return []
    if not ws:
        return cur
    if roll:
        c = cur[depth % len(cur)]
        cidx = depth % len(cur)
        cs = cur[cidx:] + cur[:cidx]
        vs = []
        for w in ws:
            u = w[depth % len(w)]
            uidx = depth % len(w)
            us = w[uidx:] + w[:uidx]
            if c == u:


                vs.append(w)
            elif lose(c) == u:
                return []
        return dfs(vs, cur, depth + 1, roll)

    assert roll == False
    nexts = [0, 1, 2]
    random.shuffle(nexts)
    for i in nexts:
        flag = True
        vs = []
        for w in ws:
            u = w[depth % len(w)]
            if i == u:
                vs.append(w)
            elif lose(i) == u:
                flag = False
                break
        if flag:
            res1 = dfs(vs, cur + [i], depth + 1, False)
            if res1:
                return res1
                
            res2 = dfs(vs, cur + [i], depth + 1, True)
            if res2:
                return res2            

    return []

def check(a, b):
    idx = 0
    while True:
        ca, cb = a[idx % len(a)], b[idx % len(b)]
        idx += 1
        if ca == cb:
            continue
        if win(ca) == cb:
            return True
        if lose(ca) == cb:
            return False


T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ws = [raw_input().lower() for i in xrange(n)]

    for i, w in enumerate(ws):
        res = Solution().repeatedSubstringPattern(w)
        if res != '':
            ws[i] = w

    ws = map(word_to_list, ws)

    res = dfs(ws, [], 0, False)

    print 'Case #%d:' % (case_ + 1),
    '''
    assert len(res) <= 500

    if res:
        for w in ws:
            assert check(res, w)
    '''
    res = list_to_word(res)
    if not res or len(res) > 500:
        print 'IMPOSSIBLE'
    else:
        print res

