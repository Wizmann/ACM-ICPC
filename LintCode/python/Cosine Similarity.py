import math

class Solution:
    """
    @param A: An integer array.
    @param B: An integer array.
    @return: Cosine similarity.
    """
    def cosineSimilarity(self, A, B):
        a = sum(
                map(
                    lambda (x, y): x * y,
                    zip(A, B)
                )
            )
        b = math.sqrt(
            sum(map(lambda x: x * x, A))
            *
            sum(map(lambda x: x * x, B))
        )
        
        return 2.0 if b == 0 else a / b
