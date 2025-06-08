import sys
sys.setrecursionlimit(10000000)
MAXI = (2 ** 32) - 1

def solve(cmds, x):
    m = len(cmds)
    i = 0
    #print cmds
    while i < m:
        cmd = cmds[i]
        if cmd[0] == 'add':
            x += cmd[1]
            i += 1
        elif len(cmd) == 3 and cmd[0] == 'for':
            loop = cmd[1]
            delta = cmd[2]
            y = solve(cmds[i + 1: i + delta], 0)
            x += y * loop
            i = i + delta + 1
        else:
            assert False

        if x > MAXI:
            return MAXI + 1
    return min(MAXI + 1, x)

n = int(raw_input())
commands = []

for i in xrange(n):
    cmd = raw_input().strip()
    if cmd == 'add':
        commands.append(('add', 1))
    elif cmd == 'end':
        commands.append(('end', -1))
    else:
        cmd, p = cmd.split()
        assert cmd == 'for'
        p = int(p)
        commands.append((cmd, p))

st = []
lf = []

for i, cmd in enumerate(commands):
    if cmd[0] == 'add':
        st.append(cmd)
    elif cmd[0] == 'end':
        st.append(cmd)
        pre = lf.pop()
        x = solve(st[pre + 1: len(st) - 1], 0)
        y = st[pre][1]
        while len(st) > pre:
            st.pop()
        st.append(('add', x * y))
    else:
        assert cmd[0] == 'for'
        st.append(cmd)
        lf.append(len(st) - 1)

#print st

res = 0
for (cmd, value) in st:
    res += value
    if res > MAXI:
        break

if res > MAXI:
    print 'OVERFLOW!!!'
else:
    print res

