#!/bin/python

import sys

def acidNaming(acid_name):
    if acid_name.startswith("hydro") and acid_name.endswith("ic"):
        return 'non-metal acid'
    elif acid_name.endswith("ic"):
        return 'polyatomic acid'
    else:
        return 'not an acid'

if __name__ == "__main__":
    n = int(raw_input().strip())
    for a0 in xrange(n):
        acid_name = raw_input().strip()
        result = acidNaming(acid_name)
        print result


