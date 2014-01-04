def calc_rook(r1, c1, r2, c2):
    if r1 != r2 and c1 != c2:
        return 2
    elif r1 == r2 and c1 == c2:
        return 0
    else:
        return 1

def calc_bishop(r1, c1, r2, c2):
    if r1 == r2 and c1 == c2:
        return 0

    if abs(r1 - r2) == abs(c1 - c2):
        return 1

    if ((r1 - r2) + (c1 - c2)) % 2 != 0:
        return 0

    return 2

def calc_king(r1, c1, r2, c2):
    if r1 == r2 and c1 == c2:
        return 0

    resa = min(abs(r1 - r2), abs(c1 - c2))
    resb = max(abs(r1 - r2), abs(c1 - c2))

    return resb

(r1, c1, r2, c2) = map(int, raw_input().split())

print calc_rook(r1, c1, r2, c2),
print calc_bishop(r1, c1, r2, c2), 
print calc_king(r1, c1, r2, c2)
