#!/bin/python

import sys

def lowestTriangle(base, area):
    return (area * 2 + base - 1) / base

base, area = raw_input().strip().split(' ')
base, area = [int(base), int(area)]
height = lowestTriangle(base, area)
print(height)

