n, q = map(int, raw_input().split())
 
maze = [[0, 0] for i in xrange(n)]
 
st = set()
 
for i in xrange(q):
    (y, x) = map(int, raw_input().split())
    y -= 1
    x -= 1
    maze[x][y] ^= 1
    lflag, rflag = False, False
    if x - 1 >= 0:
        for i in xrange(2):
            if maze[x - 1][i] == 0 and maze[x][i] == 0:
                lflag = True
    else:
        lflag = True
 
    if x + 1 < n:
        for i in xrange(2):
            if maze[x + 1][i] == 0 and maze[x][i] == 0:
                rflag = True
    else:
        rflag = True
 
    if lflag and x in st:
        st.remove(x)
    if rflag and x + 1 in st:
        st.remove(x + 1)
 
    if not lflag:
        st.add(x)
    if not rflag:
        st.add(x + 1)
 
    if st:
        print 'No'
    else:
        print 'Yes'
