class Time(object):
    def __init__(self, expr):
        self.hh, self.mm = map(int, expr.split(':'))
        
    def tick(self):
        self.mm += 1
        if self.mm == 60:
            self.hh += 1
            self.mm = 0
        if self.hh == 24:
            self.hh = 0
    
    def __str__(self):
        return '%02d:%02d' % (self.hh, self.mm)

class Solution(object):
    def nextClosestTime(self, time):
        now = Time(time)
        now.tick()
        
        while True:
            if set(list(time)) >= set(list(str(now))):
                return str(now)
            now.tick()
        return 'error'

###

class Solution(object):
    def nextClosestTime(self, time):
        t = map(int, list(time.replace(':', '')))
        
        for i in xrange(3, -1, -1):
            for item in sorted(t):
                s = t[:]
                if item <= s[i]:
                    continue
                s[i] = item
                for j in xrange(i + 1, 4):
                    s[j] = min(t)
                if self.check(s):
                    return '%d%d:%d%d' % tuple(s)
        else:
            return '%d%d:%d%d' % tuple([min(t) for i in xrange(4)])
        
    def check(self, s):
        h1, h2, m1, m2 = s
        h = h1 * 10 + h2
        m = m1 * 10 + m2
        return 0 <= h < 24 and 0 <= m < 60
