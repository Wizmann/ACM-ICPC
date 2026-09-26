#python3
s = input()

if s[-1] == 'e':
    s += 'r'
else:
    s += 'er'
print(s)

'''
^^^^^TEST^^^^
live
---------
liver
$$$$$TEST$$$$$


^^^^^TEST^^^^
femur
---------
femurer
$$$$$TEST$$$$$

^^^^^TEST^^^^
chimpanzee
---------
chimpanzeer
$$$$$TEST$$$$$

'''
