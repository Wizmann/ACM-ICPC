#!/bin/python

import math
import os
import random
import re
import sys

def init(w, h):
    res = []
    for i in xrange(h):
        res.append(['.' for j in xrange(w)])
    return res

def draw_circle(x, y, r, mat):
    n = len(mat)
    m = len(mat[0])
    for i in xrange(n):
        for j in xrange(m):
            dx = x - j
            dy = y - i
            if math.sqrt(dx ** 2 + dy ** 2) <= r:
                mat[i][j] = '#'
    return mat

def draw_square(x1, y1, x2, y2, mat):
    n = len(mat)
    m = len(mat[0])
    ps = [(x1, y1), [0, 0], (x2, y2), [0, 0]]
    ps[1][0] = ((ps[0][0] + ps[2][0]) + (ps[2][1] - ps[0][1])) / 2.0
    ps[1][1] = ((ps[0][1] + ps[2][1]) + (ps[0][0] - ps[2][0])) / 2.0
    ps[3][0] = ((ps[0][0] + ps[2][0]) - (ps[2][1] - ps[0][1])) / 2.0
    ps[3][1] = ((ps[0][1] + ps[2][1]) - (ps[0][0] - ps[2][0])) / 2.0
    area = ((x1 - x2) ** 2 + (y1 - y2) ** 2) / 2
    # print ps, area
    for i in xrange(n):
        for j in xrange(m):
            tot = 0
            for k in xrange(4):
                p1x, p1y = ps[k]
                p2x, p2y = ps[(k + 1) % 4]
                dx1, dx2 = p1x - j, p2x - j
                dy1, dy2 = p1y - i, p2y - i
                tot += 1.0 * abs(dx1 * dy2 - dx2 * dy1) / 2
            # print tot, area
            if tot - area < 1:
                mat[i][j] = '#'
    return mat

if __name__ == '__main__':
    wh = raw_input().split()

    w = int(wh[0])

    h = int(wh[1])

    circleXCircleY = raw_input().split()

    circleX = int(circleXCircleY[0])

    circleY = int(circleXCircleY[1])

    r = int(circleXCircleY[2])

    x1Y1X3Y3 = raw_input().split()

    x1 = int(x1Y1X3Y3[0])

    y1 = int(x1Y1X3Y3[1])

    x3 = int(x1Y1X3Y3[2])

    y3 = int(x1Y1X3Y3[3])

    mat = init(w, h)

    mat = draw_circle(circleX, circleY, r, mat)
    mat = draw_square(x1, y1, x3, y3, mat)

    for line in mat:
        print ''.join(line)
