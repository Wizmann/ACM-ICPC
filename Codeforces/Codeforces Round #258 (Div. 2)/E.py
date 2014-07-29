def Lucas(a, k, p):
    ret = 1
    while a and k:
        aa = a % p
        bb = k % p
        if aa < bb:
            return 0
        ret = ret * fac[aa] * pow(fac[bb] * fac[aa - bb] % p, p - 2, p) % p
        a /= p
        k /= p
    return ret

(n, s) = map(int, raw_input().split())
fs = map(int, raw_input().split())

