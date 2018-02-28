#!/bin/python

import sys
import re

s = raw_input().strip()

print len(re.findall('[A-Z]', s)) + 1
