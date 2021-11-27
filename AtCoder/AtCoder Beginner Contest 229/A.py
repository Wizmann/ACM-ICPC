my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

def dfs(maze, y, x):
    maze[y][x] = 'o'
    for i in xrange(4):
        ny = y + my[i]
        nx = x + mx[i]
        if 0 <= nx < 2 and 0 <= ny < 2 and maze[ny][nx] == '#':
            dfs(maze, ny, nx)

def do_check(maze):
    for i in xrange(2):
        for j in xrange(2):
            if maze[i][j] == '#':
                dfs(maze, i, j)
                return

def check(maze):
    do_check(maze)
    # print maze
    for line in maze:
        if '#' in line:
            return False
    return True


s1 = raw_input()
s2 = raw_input()

maze = [ list(s1), list(s2) ]

if check(maze):
    print 'Yes'
else:
    print 'No'

'''
^^^TEST^^^
##
.#
-----
Yes
$$$TEST$$$

^^^TEST^^^
.#
#.
-----
No
$$$TEST$$$

^^^TEST^^^
#.
#.
-----
Yes
$$$TEST$$$

^^^TEST^^^
#.
##
-----
Yes
$$$TEST$$$

^^^TEST^^^
#.
.#
-----
No
$$$TEST$$$

'''


