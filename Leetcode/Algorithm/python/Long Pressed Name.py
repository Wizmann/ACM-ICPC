class Solution(object):
    def isLongPressedName(self, name, typed):
        name, typed = list(name), list(typed)
        while name and typed:
            p1 = name.pop()
            c1 = 1
            while name and name[-1] == p1:
                c1 += 1
                name.pop()
            
            p2 = typed.pop()
            c2 = 1
            while typed and typed[-1] == p2:
                c2 += 1
                typed.pop()
            
            if p1 != p2 or c2 < c1:
                return False
        return not name and not typed
