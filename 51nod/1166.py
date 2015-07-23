import sys
import decimal

sys.stdin = open('input.txt')

decimal.getcontext().prec = 100000
a = decimal.Decimal(raw_input())
print '%d' % a.sqrt().to_integral(rounding=decimal.ROUND_DOWN)
