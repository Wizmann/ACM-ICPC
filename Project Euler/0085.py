TARGET = 2_000_000

def tri(x):
    return x * (x + 1) // 2

def rect_count(n, m):
    return tri(n) * tri(m)

best = {"diff": float("inf"), "n": None, "m": None, "count": None, "area": None}

n = 1
while True:
    tn = tri(n)
    # 早停：对该 n，m=1 的最小值都比当前最佳差还大，则更大的 n 只会更差
    if tn - TARGET > best["diff"]:
        break

    # 指数扩展 m 上界，再二分找到使计数 >= TARGET 的最小 m
    lo, hi = 1, 1
    while rect_count(n, hi) < TARGET:
        hi *= 2
        if hi > 100_000:  # 安全上限（对 2e6 实际用不到）
            break
    while lo < hi:
        mid = (lo + hi) // 2
        if rect_count(n, mid) >= TARGET:
            hi = mid
        else:
            lo = mid + 1

    # 比较 hi 与 hi-1 两侧谁更接近
    for m in {max(1, hi-1), hi}:
        cnt = rect_count(n, m)
        diff = abs(cnt - TARGET)
        if diff < best["diff"] or (diff == best["diff"] and n*m < best["area"]):
            best.update({"diff": diff, "n": n, "m": m, "count": cnt, "area": n*m})
    n += 1

print(best)

