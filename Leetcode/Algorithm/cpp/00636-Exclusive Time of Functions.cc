from collections import defaultdict

INF = 0x3f3f3f3f

class Process(object):
    def __init__(self, pid, pre):
        self.pid = pid
        self.t = 0
        self.pre = pre

class Solution(object):
    def exclusiveTime(self, n, logs):
        d = defaultdict(int)
        st = [Process(-1, -INF)]
        for log in logs:
            fid, status, ts = log.split(":")
            fid = int(fid)
            ts = int(ts)
            
            if status == 'start':
                st[-1].t += ts - st[-1].pre
                st.append(Process(fid, ts))
            else:
                p = st.pop()
                assert p.pid == fid
                p.t += ts - p.pre + 1
                d[fid] += p.t
                st[-1].pre = ts + 1
                
        return map(lambda x: x[1], sorted(d.items()))
