#!/usr/bin/env python
from __future__ import print_function

import sys

try:
    raw_input
except NameError:
    raw_input = input

try:
    xrange
except NameError:
    xrange = range


def main():
    T = int(raw_input())

    for _ in xrange(T):
        n = int(raw_input())

        for i in xrange(1, 2 * n - 2, 2):
            print("? %d %d" % (i, i + 1))
            sys.stdout.flush()
            res = int(raw_input())
            if res == 1:
                print("! %d" % i)
                sys.stdout.flush()
                break
        else:
            print("? %d %d" % (2 * n, 1))
            sys.stdout.flush()
            res = int(raw_input())
            if res == 1:
                print("! 1")
                sys.stdout.flush()
            else:
                print("? %d %d" % (2 * n, 2))
                sys.stdout.flush()
                res = int(raw_input())
                if res == 1:
                    print("! 2")
                else:
                    print("! %d" % (2 * n - 1))
                sys.stdout.flush()

if __name__ == "__main__":
    main()
