#!/bin/python

import sys

def caesarCipher(s, k):
    res = ''
    for c in s:
        if c.islower():
            c = chr((ord(c) - ord('a') + k) % 26 + ord('a'))
        elif c.isupper():
            c = chr((ord(c) - ord('A') + k) % 26 + ord('A'))
        res += c
    return res

if __name__ == "__main__":
    n = int(raw_input().strip())
    s = raw_input().strip()
    k = int(raw_input().strip())
    result = caesarCipher(s, k)
    print result
