from datetime import *

start = date(1901, 1, 1)
end = date(2000, 12, 31)


cnt = 0

while start <= end:
    if start.weekday() == 6 and start.day == 1:
        cnt += 1
    start += timedelta(1)

print cnt
