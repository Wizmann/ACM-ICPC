#!/usr/bin/python

T = int(raw_input())

for case_ in xrange(T):
    (a_, b_, d_, n_) = map(int, raw_input().split())
    if n_ < 5:
        print list(str(a_ * b_ * ((10 ** n_) - 1) / 9)).count(str(d_))
    else:
        d = {}
        if a_ * b_ < 10:
            d[a_ * b_] = n_
        else:
            a = a_ * b_ % 10
            b = a_ * b_ / 10
            #print '>>', a, b
            d[a] = d.get(a, 0) + 1
            if a + b >= 10:
                if b + 1 >= 10:
                    d[0] = d.get(0, 0) + 1
                    d[1] = d.get(1, 0) + 1
                else:
                    d[b + 1] = d.get(b + 1, 0) + 1
            else:
                d[b] = d.get(b, 0) + 1
            
            c = (a + b) % 10
            d[c] = d.get(c, 0) + 1
        
            x = (a + b + (a + b) / 10) % 10
            d[x] = d.get(x, 0) + n_ - 2
        print d.get(d_, 0)
