n = int(raw_input())

cmds = []

APPEND = 1
DELETE = 2
PRINT = 3
UNDO = 4

res = ''

def process(cmd, param, is_undo=False):
    global res
    global cmds
    if cmd == APPEND:
        res += param
        if not is_undo:
            cmds.append((DELETE, len(param)))
    elif cmd == DELETE:
        k = int(param)
        deleted = res[-k:]
        res = res[:-k]
        if not is_undo:
            cmds.append((APPEND, deleted))
    elif cmd == PRINT:
        k = int(param)
        print res[k - 1]
    elif cmd == UNDO:
        cmd, param = cmds.pop()
        process(cmd, param, True)
    else:
        assert False
    # print '>>', res, cmds

for i in xrange(n):
    cmd = raw_input()
    param = None
    if not cmd.startswith("4"):
        cmd, param = cmd.split()
    cmd = int(cmd)
    process(cmd, param)

