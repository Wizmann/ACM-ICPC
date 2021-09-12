q = int(raw_input())
days = raw_input()

print 'Yes' if days[q - 1] == 'o' else 'No'

'''
^^^TEST^^^
4
oooxoox
-------
No
$$$TEST$$$

^^^TEST^^^
7
ooooooo
-------
Yes
$$$TEST$$$
'''

