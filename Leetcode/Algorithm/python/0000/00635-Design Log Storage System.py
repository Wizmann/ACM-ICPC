import re

class LogSystem(object):

    def __init__(self):
        self.logs = []

    def put(self, id, timestamp):
        """
        :type id: int
        :type timestamp: str
        :rtype: void
        """
        self.logs.append((timestamp, id))
        

    def retrieve(self, s, e, gra):
        """
        :type s: str
        :type e: str
        :type gra: str
        :rtype: List[int]
        """
        s, e = self.makeSE(s, e, gra)
        #print s, e
        return map(lambda (tm, id): id, filter(lambda (tm, id): s <= tm <= e, self.logs))
    
    def makeSE(self, s, e, gra):
        d = {
            'Year':   0,
            'Month':  1,
            'Day':    2,
            'Hour':   3,
            'Minute': 4,
            'Second': 5
        }
        
        
        idx = d[gra]
        s = s.split(':')
        for i in xrange(idx + 1, 6):
           s[i] = re.sub('[0-9]', '0', s[i])
        
        e = e.split(':')
        for i in xrange(idx + 1, 6):
            e[i] = re.sub('[0-9]', '9', e[i])
        
        return ':'.join(s), ':'.join(e)
