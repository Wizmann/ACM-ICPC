#!/bin/python

import math
import os
import random
import re
import sys
from collections import Counter

def birthdayCakeCandles(ar):
    c = Counter(ar)
    return max(c.items(), key=lambda x:x[1])[1]    
    
if __name__ == '__main__':
    fptr = sys.stdout

    ar_count = int(raw_input())

    ar = map(int, raw_input().rstrip().split())

    print birthdayCakeCandles(ar)
