import decimal

(a, b) = raw_input().split()

decimal.getcontext().prec = 4000
while a[-1] == '0':
    a = a[:-1]

c = decimal.Decimal(a) ** decimal.Decimal(b)
print '{0:f}'.format(c).replace('0.', '.')
