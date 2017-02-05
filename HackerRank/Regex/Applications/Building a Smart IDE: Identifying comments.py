import sys
import re

code = sys.stdin.read()

g = re.findall("((?://.*)|(?:/\*[.\s\S]*?\*/))", code)
for snippet in g:
    for line in snippet.split('\n'):
        print line.strip()
