#python3
T = int(input())

for case_ in range(T):
    print('Case #%d:' % (case_ + 1), end=' ')

    name = input()

    if name[-1].lower() in 'aeiou':
        print("%s is ruled by Alice." % name)
    elif name[-1].lower() == 'y':
        print("%s is ruled by nobody." % name)
    else:
        print("%s is ruled by Bob." % name)

'''
^^^TEST^^^
3
Mollaristan
Auritania
Zizily
-------
Case #1: Mollaristan is ruled by Bob.
Case #2: Auritania is ruled by Alice.
Case #3: Zizily is ruled by nobody.
$$$TEST$$$
'''


