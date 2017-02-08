import sys
import re

html = sys.stdin.read()
g = re.findall("<a href=\"(.*?)\".*?>(?:<.*?>)?(.*?)(?:<.*?>)?</a>", html)
for (href, text) in g:
    print '%s,%s' % (href, text.strip())
