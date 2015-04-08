print 'pangram' if len(set(''.join(raw_input().lower().split()))) == 26 else 'not pangram'
