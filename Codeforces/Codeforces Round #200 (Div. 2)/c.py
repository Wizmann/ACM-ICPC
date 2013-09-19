#coding=utf-8
ans = 0

def process(a, b):
    global ans
    ans += a / b
    a = a % b
    if a:
        process(b, a)
        
(a, b) = map(int, raw_input().split())
process(a, b)
print ans
