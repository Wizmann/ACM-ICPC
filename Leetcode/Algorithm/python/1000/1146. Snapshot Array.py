class SnapshotArray(object):

    def __init__(self, length):
        self.length = length
        self.snaps = []
        self.changes = [[] for i in xrange(length)]
        self.idx = 0

    def set(self, index, val):
        if not self.changes[index] or self.changes[index][-1][0] != self.idx:
            self.changes[index].append([self.idx, val])
        elif self.changes[index] and self.changes[index][-1][0] == self.idx:
            self.changes[index][-1][1] = val        

    def snap(self):
        self.idx += 1
        return self.idx - 1
        
    def get(self, index, snap_id):
        l, r = 0, len(self.changes[index]) - 1
        while l <= r:
            m = (l + r) >> 1
            #print l, r, m
            (idx, value) = self.changes[index][m]
            if idx <= snap_id:
                l = m + 1
            else:
                r = m - 1
        #print l, r
        if r == -1:
            return 0
        return self.changes[index][r][1]
        

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
