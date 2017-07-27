#!/bin/python

import sys

def make_step(delta):
    step = 0

    step += delta / 5
    delta %= 5
    step += delta / 2
    delta %= 2
    return step + delta

def solve(ns):
    n = len(ns)
    minn = min(ns)
    minstep = 10 ** 10

    for i in xrange(minn - 4, minn + 1):
        step = 0
        for item in ns:
            step += make_step(item - i)
        minstep = min(minstep, step)

    return minstep

assert solve([1, 10, 20]) == 7
assert solve([512, 125, 928, 381, 890, 90, 512, 789, 469, 473, 908, 990, 195, 763, 102, 643, 458, 366, 684, 857, 126, 534, 974, 875, 459, 892, 686, 373, 127, 297, 576, 991, 774, 856, 372, 664, 946, 237, 806, 767, 62, 714, 758, 258, 477, 860, 253, 287, 579, 289, 496]) == 5104
assert solve([3, 2, 2, 7]) == 2

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = map(int, raw_input().split())

        print solve(ns)

