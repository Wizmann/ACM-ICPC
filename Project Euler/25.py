step = 2
a = 1
b = 1

while True:
    c = a + b
    a = b
    b = c
    step += 1
    
    if len(str(c)) >= 1000:
        break
        
print step
