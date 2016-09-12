from collections import Counter
def longest_word(letters):
    c = Counter(letters)
    max_l = -1
    ans = []
    for word in words:
        w = Counter(word)
        for key, value in w.items():
            if c.get(key, 0) < value:
                break
        else:
            if len(word) > max_l:
                ans = [word]
                max_l = len(word)
            elif len(word) == max_l:
                ans.append(word)
                
    return None if not ans else sorted(ans)
