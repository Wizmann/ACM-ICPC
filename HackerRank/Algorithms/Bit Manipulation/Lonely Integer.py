#!/usr/bin/py
def lonelyinteger(a):
    return reduce(lambda x, y: x ^ y, a, 0)

if __name__ == '__main__':
    a = input()
    b = map(int, raw_input().strip().split(" "))
    print lonelyinteger(b)

