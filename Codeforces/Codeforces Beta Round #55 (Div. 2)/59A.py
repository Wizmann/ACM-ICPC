def solve(word):
    lower, upper = 0, 0
    for c in word:
        if c.islower():
            lower += 1
        else:
            upper += 1
    if lower >= upper:
        return word.lower()
    else:
        return word.upper()

assert solve("HoUse") == "house"
assert solve("ViP") == "VIP"
assert solve("aaBB") == "aabb"

word = raw_input()
print solve(word)