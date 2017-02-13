import sys
import re

emails = []

for line in sys.stdin:
    g = re.findall("([\w._]+@\w+\.\w+(?:\.\w+)*)", line)
    emails += g
print ';'.join(sorted(set(emails)))
