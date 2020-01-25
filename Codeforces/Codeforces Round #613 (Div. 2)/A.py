from collections import Counter
 
def solve(commands):
    c = Counter(commands)
    l, r = c.get('L', 0), c.get('R', 0)
    return l + r + 1
 
assert solve("LRLR") == 5
assert solve("LR") == 3
 
n = int(raw_input())
print solve(raw_input())
