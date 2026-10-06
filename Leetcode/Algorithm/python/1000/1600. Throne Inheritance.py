from collections import defaultdict

class ThroneInheritance(object):

    def __init__(self, kingName):
        self.children = defaultdict(list)
        self.children[kingName] = []
        self.king = kingName
        self.dead = set()

    def birth(self, parentName, childName):
        self.children[parentName].append(childName)
        

    def death(self, name):
        self.dead.add(name) 

    def getInheritanceOrder(self):
        return self.dfs(self.king)
    
    def dfs(self, cur):
        res = []
        if cur not in self.dead:
            res.append(cur)
        for child in self.children[cur]:
            res += self.dfs(child)
        return res     
        


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
