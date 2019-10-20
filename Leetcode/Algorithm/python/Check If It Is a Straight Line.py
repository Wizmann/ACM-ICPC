INF = 10 ** 10

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

class Solution(object):
    def checkStraightLine(self, points):
        pivot = min(points)
        
        st = set()
        for (y, x) in points:
            py, px = pivot
            if py == y and px == x:
                continue
            dy = (py - y)
            dx = (px - x)
            
            if dx == 0:
                st.add(INF)
            elif dy == 0:
                st.add(0)
            else:
                s = 1
                if dy * dx < 0:
                    s = -1
                    dy, dx = abs(dy), abs(dx)
                g = gcd(dy, dx)
                st.add((s * dy / g, dx / g))
        return len(st) == 1
                    
        
