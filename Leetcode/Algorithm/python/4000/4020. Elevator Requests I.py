import numpy as np

class Solution(object):
    def elevatorRequests(self, n, requests):
        requests = np.asarray(requests)
        if requests.size == 0:
            return 0

        return int(np.abs(np.diff(np.concatenate(([0], requests)))).sum())
