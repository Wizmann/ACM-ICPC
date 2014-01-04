(w, m, k) = map(int, raw_input().split())

sum_num = 0
st = m

for i in xrange(1, 100):
    end = (10 ** i) - 1
    if st > end:
        continue

    max_cnt = end - st + 1
    max_cost = max_cnt * k * i

    if max_cost <= w:
        sum_num += max_cnt
        w -= max_cost
        st = 10 ** i
    else:
        sum_num += w / (i * k)
        break

print sum_num


