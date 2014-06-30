ls = filter(lambda y: y, map(lambda x: x.strip(), raw_input()[1:-1].split(",")))
print len(set(ls))
