INF = 0xdeadbeef

def solve():
    (n, m) = map(int, raw_input().split())
    stubs = [{'pos': 1, 'value': 0}]
    for i in xrange(m):
        (a, b) = map(int, raw_input().split())
        stubs.append({
            'pos': a,
            'value': b,
        })
    stubs.append({
        'pos': n, 
        'value': n - 1
    })
    
    stubs = sorted(stubs, key=lambda x: x['value'])
    
    u = len(stubs)
    
    for i in xrange(u):
        stub = stubs[i]
        for j in xrange(i):
            stub['value'] = min(stub['value'], stubs[j]['value'] + abs(stub['pos'] - stubs[j]['pos']))
            
    stubs = sorted(stubs, key=lambda x: x['pos'])
    ans = 0
    for i in xrange(u - 1):
        a, b = stubs[i], stubs[i + 1]
        pos_diff = b['pos'] - a['pos']
        val_diff = b['value'] - a['value']
        
        ans = max(
                ans, 
                a['value'], 
                b['value'],
                a['value'] + (pos_diff + val_diff) / 2)
    return ans


T = int(raw_input())

for case_ in xrange(T):
    print solve()
