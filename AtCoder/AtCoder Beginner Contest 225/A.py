from itertools import permutations
s = raw_input()
s = sorted(s)

print len(set(permutations(s)))



'''

^^^TEST^^^
aba
-------
3
$$$TEST$$$

^^^TEST^^^
abc
-------
6
$$$TEST$$$

'''
