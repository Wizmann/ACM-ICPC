def solve(s):
    d = {'R': 0, 'G': 0, 'B': 0}
    ans = 0
    for item in s:
        for (key, value) in d.items():
            if value >= 2:
                ans += 2
            elif value == 1:
                ans += 1
        d[item] += 1
    return ans
    
T = int(raw_input())
for i in xrange(T):
    s = raw_input()
    print solve(s)
