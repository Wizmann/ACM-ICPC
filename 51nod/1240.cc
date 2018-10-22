def miu(n):
    num = 0
    
    i = 2
    while i * i <= n:
        cnt = 0

        if n % i == 0:
            num += 1     
            while n%i == 0:
                n /= i   
                cnt += 1  
            if cnt >= 2:
                return 0
        i += 1
    if n > 1:
        num += 1
    return 1 if num%2 == 0 else -1 
    
print miu(int(raw_input()))
