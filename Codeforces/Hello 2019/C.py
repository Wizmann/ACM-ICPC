from collections import defaultdict

def check(s):
    st = []
    for c in s:
        if c == '(':
            st.append(c)
        elif st:
            st.pop()
        else:
            return None
    return st

def reverse(s):
    return s.replace('(', '*').replace(')', '(').replace('*', ')')[::-1]

assert check('((') == ['(', '(']
assert check('))') == None
assert reverse('(()') == '())'


if __name__ == '__main__':
    n = int(raw_input())
    l, r = defaultdict(list), defaultdict(list)
    res = 0
    s = set()
    for i in xrange(n):
        u = raw_input().strip()
        ll = check(u)
        rr = check(reverse(u))
        #print l, r
        flag = False
        if ll is not None and not flag:
            while len(ll) in r and r[len(ll)]:
                v = r[len(ll)].pop()
                if v not in s:
                    continue
                s.remove(v)
                res += 1
                flag = True
                break
            else:
                l[len(ll)].append(i)
        if rr is not None and not flag:
            while len(rr) in l and l[len(rr)]:
                v = l[len(rr)].pop()
                if v not in s:
                    continue
                s.remove(v)
                res += 1
                flag = True
                break
            else:
                r[len(rr)].append(i)

        s.add(i)

    print res

