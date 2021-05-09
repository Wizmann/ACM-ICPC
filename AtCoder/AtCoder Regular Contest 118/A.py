
def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    g = gcd(a, b)
    return a / g * b

t, N = map(int, raw_input().split())

x = (100 * N - 1) / t
# print x
print x + (t * x / 100) + 1

'''
^^^TEST^^^
10 1
----
10
$$$TEST$$$  

^^^TEST^^^
3 5
----
171
$$$TEST$$$  


^^^TEST^^^
1 1000000000
----
100999999999
$$$TEST$$$  
'''


