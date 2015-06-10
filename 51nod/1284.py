n = int(raw_input())

t = 0
t += n / 2
t += n / 3
t += n / 5
t += n / 7
t -= n / 2 / 3
t -= n / 2 / 5
t -= n / 2 / 7
t -= n / 3 / 5
t -= n / 3 / 7
t -= n / 5 / 7
t += n / 2 / 3 / 5
t += n / 2 / 3 / 7
t += n / 2 / 5 / 7
t += n / 3 / 5 / 7
t -= n / 2 / 3 / 5 / 7

print n - t
