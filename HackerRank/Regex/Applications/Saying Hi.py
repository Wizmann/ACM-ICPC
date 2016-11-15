import re
import sys

n = int(raw_input())

for line in sys.stdin:
    line = line.strip()
    if re.search(r'^[Hh][Ii] [^Dd]', line):
        print line
