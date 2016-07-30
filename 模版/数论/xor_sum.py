def xor_sum(x):
    res = 0
    for i in xrange(1, 64):
        y = (x + 1) % (1 << i) - (1 << (i - 1))
        z = (x + 1) / (1 << i)
        ones = z * (1 << (i - 1)) + max(0, y)
        if ones % 2 == 1:
            res |= 1 << (i - 1)
    return res
    
for i in xrange(1024):
    assert xor_sum(i) == reduce(lambda x, y: x ^ y, range(i + 1))

def xor_sum_even(x):
    # xor_sum(2, 4, 6 ... x)
    x = (x + 1) / 2
    return xor_sum(x) << 1
    
for i in xrange(2, 1024, 2):
    assert xor_sum_even(i) == reduce(lambda x, y: x ^ y, range(2, i + 1, 2))
    
def xor_sum_odd(x):
    # xor_sum(1, 3, 5, ... x)
    return (xor_sum(x / 2) << 1) | ((x + 1) / 2 % 2)

for i in xrange(1, 1024, 2):
    assert xor_sum_odd(i) == reduce(lambda x, y: x ^ y, range(1, i + 1, 2))
