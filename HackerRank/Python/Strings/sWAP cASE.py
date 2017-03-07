def swap_case(s):
    return ''.join(map(lambda x: x.lower() if x.isupper() else x.upper(), s))
    
if __name__ == '__main__':
    s = raw_input()
    result = swap_case(s)
    print result
