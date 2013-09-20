#coding=utf-8
#4523406	 Sep 20, 2013 10:18:43 PM	Wizmann	 C - Quiz	 Python 2	Accepted	92 ms	0 KB

(n, m, k) = map(int, raw_input().split())

fill = n - (n / k)

#print fill

if m <= fill:
    print m % 1000000009
else:
    doub = m - fill
    #print doub
    score = k * (pow(2, (doub + 1), 1000000009) - 2) 

    score += m - doub * k
    print score % 1000000009
