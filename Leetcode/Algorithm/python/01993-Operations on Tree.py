class LockingTree(object):

    def __init__(self, parent):
        self.parent = parent
        self.n = len(parent)
        self.children = [ [] for i in xrange(self.n) ]
        for i, p in enumerate(parent):
            if p == -1:
                continue
            self.children[p].append(i)
        self.ld = {}

    def lock(self, num, user):
        if num not in self.ld:
            self.ld[num] = user
            return True
        return False

    def unlock(self, num, user):
        if self.ld.get(num, -1) == user:
            del self.ld[num]
            return True
        return False

    def upgrade(self, num, user):
        cur = num
        while cur != -1:
            if cur in self.ld:
                return False
            cur = self.parent[cur]

        if self.dfs(num) == 0:
            return False

        self.ld[num] = user
        return True
    
    def dfs(self, cur):
        cnt = 0
        for child in self.children[cur]:
            if child in self.ld:
                cnt += 1
                del self.ld[child]
            cnt += self.dfs(child)
        return cnt

# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
