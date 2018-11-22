import re

class LogEntry(object):
    def __init__(self, idx, log):
        self.idx = idx
        self.idt = log.split()[0]
        self.rem = ' '.join(log.split()[1:])
        self.log = log
        self.tp = 1 if re.match('\d', self.rem) else 0
        
    def to_cmp_str(self):
        if self.tp == 1:
            return (self.tp, self.idx, self.log)
        else:
            return (self.tp, self.rem, self.idt, self.log)
            
    def __str__(self):
        return self.log

class Solution(object):
    def reorderLogFiles(self, logs):
        logs = map(lambda (i, log): LogEntry(i, log), enumerate(logs))
        logs.sort(key=lambda x: x.to_cmp_str())
        return map(lambda x: x.log, logs)
