#python3
word = input()

print({
    'red': 'SSS',
    'blue': 'FFF',
    'green': 'MMM'
}.get(word, 'Unknown'))

'''

^^^^TEST^^^^
red
-------
SSS
$$$TEST$$$

^^^^TEST^^^^
blue
-------
FFF
$$$TEST$$$

^^^^TEST^^^^
green
-------
MMM
$$$TEST$$$

^^^^TEST^^^^
atcoder
-------
Unknown
$$$TEST$$$


'''
