def solve(s):
    res = ''
    pre = 0
    for c in s:
        u = ord(c) - ord('a')
        if u <= pre and pre <= 25:
            res += chr(ord('a') + pre)
            pre += 1
        else:
            res += c
    return "-1" if pre <= 25 else res

assert solve("fuck") == "-1"
assert solve("aacceeggiikkmmooqqssuuwwyy") == "abcdefghijklmnopqrstuvwxyz"
assert solve("aacceeggiikkmmooqqssuuwwyyzzzz") == "abcdefghijklmnopqrstuvwxyzzzzz"

if __name__ == '__main__':
    s = raw_input()
    print solve(s)
