from itertools import permutations

PRIMES = [2, 3, 5, 7, 11, 13, 17]

def isgood(v):
    v = str(v)
    num = v[1:3]
    p = 0
    for item in v[3:]:
        num += item
        u = int(num)
        if u % PRIMES[p] != 0:
            return False
        p += 1
        num = num[1:]
    return True

def main():
    ans = 0
    for perm in permutations(map(str, range(0, 10))):
        v = ''.join(perm)
        if v[0] != '0' and isgood(int(v)):
            print v
            ans += int(v)
    return ans

if __name__ == '__main__':
    print main()