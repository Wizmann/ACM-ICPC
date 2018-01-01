import datetime



if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (y1, m1, d1) = map(int, raw_input().split())
        (y2, m2, d2) = map(int, raw_input().split())
        
        delta = y2 - y1
        y1 = y1 % 2000 + 2000
        y2 = y1 + delta

        dt1 = datetime.date(y1, m1, d1);
        dt2 = datetime.date(y2, m2, d2);

        res = 0
        while dt1 <= dt2:
            if dt1.day == 1 and dt1.weekday() == 6:
                res += 1
            if dt1.month != 12:
                dt1 = datetime.date(dt1.year, dt1.month + 1, 1)
            else:
                dt1 = datetime.date(dt1.year + 1, 1, 1)

        print res
