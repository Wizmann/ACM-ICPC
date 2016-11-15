import re

regexs = [
    '^hackerrank$|^hackerrank.*hackerrank$',
    '^hackerrank',
    'hackerrank$',  
]

n = int(raw_input())
for i in xrange(n):
    s = raw_input()
    for i, regex in enumerate(regexs):
        if re.search(regex, s):
            print i
            break
    else:
        print -1

