units = ["zero", "one", "two", "three", "four",  "five", 
    "six", "seven", "eight", "nine"]
teens = ["ten", "eleven", "twelve", "thirteen",  "fourteen", 
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["", "ten", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"]

def int2word(v):
    if v < 10:
        return units[v]
    elif v < 19:
        return teens[v - 10]
    else:
        ans = []
        hu = v / 100 % 10
        te = v / 10 % 10
        on = v % 10

        if hu:
            ans.append(units[hu])
            ans.append('hundred')

            if te or on:
                ans.append('and')

        if te >= 2:
            ans.append(tens[te])
            if on:
                ans.append(units[on])
        elif te:
            ans.append(teens[on])
        elif on:
            ans.append(units[on])
    return ans

ss = 0
for i in xrange(1, 1000):
    print int2word(i)
    word = len("".join(int2word(i)))
    print "".join(int2word(i))
    ss += word
print ss + len("onethousand")
