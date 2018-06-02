(n, m) = map(int, raw_input().split())
 
ns = [0] + map(int, raw_input().split())
 
add = 0
for i in xrange(m):
    cmd = raw_input().strip()
    if cmd[0] == '1':
        t, v, x = map(int, cmd.split())
        ns[v] = x - add
    elif cmd[0] == '2':
        t, y = map(int, cmd.split())
        add += y
    else:
        t, q = map(int, cmd.split())
        print ns[q] + add