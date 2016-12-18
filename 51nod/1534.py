def solve(xp, yp, xv, yv):
    if xp + yp <= max(xv, yv):
        return True
    ta, tb = 0, 0
    while xv >= 0 and yv >= 0:
        if xv <= xp and yv <= yp:
            ta = xp + yp - xv - yv
            if ta <= tb:
                return True
        tb += 1
        xv -= 1
        yv -= 1
    return False
    
assert solve(2, 1, 2, 2) == True
assert solve(1, 1, 0, 1) == False
assert solve(20, 0, 7, 22) == True

(xp, yp, xv, yv) = map(int, raw_input().split())

print 'Polycarp' if solve(xp, yp, xv, yv) else 'Vasiliy'
