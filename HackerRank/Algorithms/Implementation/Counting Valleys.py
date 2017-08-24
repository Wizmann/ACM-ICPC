n = int(raw_input())
s = raw_input()

pre = 0
height = 0
cnt = 0
for item in s:
    if item == 'U':
        height += 1
    else:
        height -= 1
    if pre >= 0 and height < 0:
        cnt += 1
    pre = height
print cnt
