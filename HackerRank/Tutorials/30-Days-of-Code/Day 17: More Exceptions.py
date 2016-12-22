class Calculator(object):
    def power(self, n, p):
        assert n >= 0 and p >= 0, 'n and p should be non-negative'
        return n ** p
        
myCalculator=Calculator()
T=int(raw_input())
for i in range(T):
    n,p = map(int, raw_input().split())
    try:
        ans=myCalculator.power(n,p)
        print ans
    except Exception,e:
        print e    
    
