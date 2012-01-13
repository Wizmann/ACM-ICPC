import sys
from math import sqrt

if(__name__=='__main__'):
    n=raw_input()
    n=int(n)
    
    minAns=1L<<64
    maxAns=-minAns
    for i in xrange(1,int(sqrt(n))+5):
        if(n%i==0):
            m=n/i
            for j in xrange(1,int(sqrt(m))+5):
                if(m%j==0):
                    ret=i+1
                    ret=ret*(j+2)*(m/j+2)-n
                    maxAns=max(ret,maxAns)
                    if(ret>0): minAns=min(ret,minAns)
                    
                    ret=i+2
                    ret=ret*(j+1)*(m/j+2)-n
                    maxAns=max(ret,maxAns)
                    if(ret>0): minAns=min(ret,minAns)
                    
                    ret=i+2
                    ret=ret*(j+2)*(m/j+1)-n
                    maxAns=max(ret,maxAns)
                    if(ret>0): minAns=min(ret,minAns)
    print minAns,maxAns
