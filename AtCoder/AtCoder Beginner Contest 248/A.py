s = raw_input()

print list(set(s) ^ set('0123456789'))[0]

'''
^^^^TEST^^^
459230781
------
6
$$$TEST$$$
'''
