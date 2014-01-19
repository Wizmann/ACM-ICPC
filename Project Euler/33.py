def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def main():
    A = B = 1
    for a in xrange(10, 100):
        for b in xrange(a + 1, 100):
            x = a % 10
            y = b / 10
            
            if x != y:
                continue
            
            x = a / 10
            y = b % 10
            
            if y == 0:
                continue
            
            if x / gcd(x, y) == a / gcd(a, b) and \
                    y / gcd(x, y) == b / gcd(a, b):
                #print A, B
                A *= a
                B *= b
    print B / gcd(A, B)

main()
                
