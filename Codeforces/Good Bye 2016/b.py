def on_pole(cur):
    return cur in [0, 20000]

def solve(moves):
    cur = 0
    for (distance, direction) in moves:
        if direction in ['East', 'West']:
            if on_pole(cur):
                return False
            else:
                continue

        if cur == 0: # north pole
            if direction != 'South':
                return False
        if cur == 20000: # south pole
            if direction != 'North':
                return False

        if direction == 'North':
            cur -= distance
            if cur < 0:
                return False

        if direction == 'South':
            cur += distance
            if cur > 20000:
                return False
    return cur == 0

assert solve([
(7500  , "South"),
(10000 , "East"),
(3500  , "North"),
(4444  , "West"),
(4000  , "North")
]) == True

assert solve([
(15000 , "South"),
(4000  , "East")
]) == False

assert solve([
(20000   , "South"),
(1000    , "North"),
(1000000 , "West"),
(9000    , "North"),
(10000   , "North")
]) == True

assert solve([
(20000 , "South"),
(10    , "East"),
(20000 , "North"),
]) == False


if __name__ == '__main__':
    n = int(raw_input())

    moves = []
    for i in xrange(n):
        (a, b) = raw_input().split()
        a = int(a)
        moves.append((a, b))

    print 'YES' if solve(moves) else 'NO'
