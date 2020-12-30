from collections import defaultdict, Counter
from random import randint

class MajorityChecker(object):

    def __init__(self, arr):
        self.arr = arr
        self.d = defaultdict(list)
        
        for i, num in enumerate(arr):
            self.d[num].append(i)

    def query(self, left, right, threshold):
        st = set()
        m = right - left + 1
        for i in xrange(10):
            r = randint(0, m - 1)
            c = self.arr[left + r]
            if c in st:
                continue
            st.add(c)
            cnt = self.count(c, left, right)
            if cnt >= threshold:
                return c
        return -1
    
    def count(self, num, left, right):
        l = self.do_count(num, left - 1)
        r = self.do_count(num, right)
        return r - l
    
    def do_count(self, num, pos):
        if pos == -1:
            return 0
        arr = self.d[num]
        l, r = 0, len(arr) - 1
        while l <= r:
            m = (l + r) / 2
            if arr[m] > pos:
                r = m - 1
            else:
                l = m + 1
        return l
