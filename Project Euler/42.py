def trinum(s):
    now = 1
    step = s

    while step:
        half = step >> 1
        mid = now + half

        next = mid * (mid + 1) / 2

        if next >= s:
            step = half
        else:
            now = mid + 1
            step = step - half - 1
    return now

def is_trinum(s):
    v = trinum(s)
    return v * (v + 1) / 2 == s

def word_to_int(word):
    s = 0
    for ch in word:
        s += ord(ch) - ord('A') + 1
    return s

def main():
    with open("words.txt") as wordsfile:
        ans = 0
        words = filter(lambda x: x,
                    map(lambda y: y.replace('\"', ''),
                        wordsfile.read().split(',')))
        for word in words:
            s = word_to_int(word)
            if is_trinum(s):
                ans += 1
        print ans

def test():
    assert is_trinum(1) == True
    assert is_trinum(2) == False
    assert is_trinum(37) == False
    assert is_trinum(45) == True
    print ' '.join(map(str, [i for i in xrange(100) if is_trinum(i)]))
    assert word_to_int('SKY') == 55
    assert is_trinum(55) == True

if __name__ == '__main__':
    test()
    main()