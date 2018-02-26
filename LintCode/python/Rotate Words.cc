class Solution:
    """
    @param: words: A list of words
    @return: Return how many different rotate words
    """
    def countRotateWords(self, words):
        assert self.rotate_sort("picture") == "cturepi"
        assert self.rotate_sort("aabb") == "aabb"
        assert self.rotate_sort("abba") == "aabb"
        assert self.rotate_sort("bbaa") == "aabb"

        return len(set([self.rotate_sort(word) for word in words]))

    def rotate_sort(self, word):
        n = len(word)
        p, q = 0, 1

        while p < n and q < n:
            if word[p] < word[q]:
                q += 1
            elif word[p] > word[q]:
                p = q
                q += 1
            else:
                for i in xrange(n):
                    pp = (p + i) % n
                    qq = (q + i) % n

                    if word[pp] > word[qq]:
                        p, q = q, q + i
                        break
                    if word[pp] < word[qq]:
                        q = q + i + 1
                        break
                else:
                    break

        return word[p:] + word[:p]
