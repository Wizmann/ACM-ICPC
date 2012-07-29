#Result:2012-07-29 20:36:59	 Accepted	3629	Python	300	320	Wizmann
import sys
from math import sqrt


def slove(x):
    if(x<0):return 0
    elif(x==0): return 1
    else:
        m=int(sqrt(x))-1
        if(m&1): m-=1
        res=0
        if(m>2):     
            res=2*(2+m)*m/2/2+m/2+1
        else:
            if(m==0):
                res=1
            else:
                res=6
        m=int(sqrt(x))
        if(not m&1):
            res+=min(x+1-m*m,2*m+1)
    return res


if(__name__=='__main__'):
    for lines in sys.stdin:
        [a,b]=[int(x) for x in lines.split()]
        print(slove(b)-slove(a-1))
