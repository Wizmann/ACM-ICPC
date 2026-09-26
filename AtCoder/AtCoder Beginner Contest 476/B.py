#python3
n = int(input())
s = input()
t = input()

for i in range(n):
    if not (s[i] == t[i] or t[i] == '*'):
        print('No')
        break
else:
    print('Yes')

'''
^^^^^^TEST^^^^
8
chokudai
**o*u*ai
--------
Yes
$$$$$$TEST$$$$$

^^^^^^TEST^^^^
5
snuke
snake
--------
No
$$$$$$TEST$$$$$

^^^^^^TEST^^^^
5
yiwiy
*****
--------
Yes
$$$$$$TEST$$$$$
'''
