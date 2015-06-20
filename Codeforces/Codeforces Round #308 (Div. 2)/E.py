import sys
import re

exp_str = raw_input()

ps = [-1] + [m.start() for m in re.finditer('\*', exp_str)] + [len(exp_str)]

if not ps:
    print eval(exp_str)
else:
    ans = eval(exp_str)
    n = len(ps)
    for i in xrange(n):
        for j in xrange(i + 1, n):
            ii = ps[i]
            jj = ps[j]
            s = exp_str[:ii + 1] + "(" + exp_str[ii + 1: jj] + ")" + exp_str[jj:]
            ans = max(ans, eval(s))
            
    print ans
