def no_leading_zero(s):
    res = ''
    flag = False

    for c in s:
        if c == '0':
            if not flag:
                continue
        else:
            flag = True
        res += c
    return res

a = raw_input()
b = raw_input()

a = no_leading_zero(a)
b = no_leading_zero(b)

if len(a) > len(b):
    print '>'
elif len(a) < len(b):
    print '<'
else:
    if a < b:
        print '<'
    elif a > b:
        print '>'
    else:
        print '='
