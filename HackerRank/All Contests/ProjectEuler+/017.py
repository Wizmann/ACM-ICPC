def ones(u):
    return [
        'Zero',
        'One',
        'Two',
        'Three',
        'Four',
        'Five',
        'Six',
        'Seven',
        'Eight',
        'Nine',
        'Ten',
        'Eleven',
        'Twelve',
        'Thirteen',
        'Fourteen',
        'Fifteen',
        'Sixteen',
        'Seventeen',
        'Eighteen',
        'Nineteen'
    ][u]

def tens(u):
    return [
        '',
        '',
        'Twenty',
        'Thirty',
        'Forty',
        'Fifty',
        'Sixty',
        'Seventy',
        'Eighty',
        'Ninety'
    ][u]

def hundreds(u):
    if u == 0:
        return ''
    return ones(u) + ' ' + 'Hundred'

def speak1(n):
    assert 0 <= n < 1000

    res = ''
    if n >= 100:
        a, b = n / 100, n % 100
        res = hundreds(a)

        n = b

    if n < 20:
        if res and not n:
            pass
        else:
            res += ' ' + ones(n)
    elif n < 100:
        a, b = n / 10, n % 10
        res += ' ' + tens(a)
        if b:
            res += ' ' + ones(b)
    return res.strip()

assert speak1(100) == 'One Hundred'
assert speak1(101) == 'One Hundred One'
assert speak1(119) == 'One Hundred Nineteen'
assert speak1(191) == 'One Hundred Ninety One'

def speak2(n):
    if n == 0:
        return 'Zero'

    b = n / (10 ** 9) % 1000
    m = n / (10 ** 6) % 1000
    t = n / 1000 % 1000
    d = n % 1000

    bs = '' if b == 0 else speak1(b) + ' Billion'
    ms = '' if m == 0 else speak1(m) + ' Million'
    ts = '' if t == 0 else speak1(t) + ' Thousand'
    ds = '' if d == 0 else speak1(d) + ''

    return ' '.join(' '.join([bs, ms, ts, ds]).split())

assert speak2(10001) == 'Ten Thousand One'

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print speak2(n)



