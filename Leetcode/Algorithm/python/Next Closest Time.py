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
