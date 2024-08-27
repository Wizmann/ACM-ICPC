def likes(names):
    if not names:
        return 'no one likes this'
    elif len(names) == 1:
        return '%s likes this' % names[0]
    elif len(names) in [2, 3]:
        return '%s and %s like this' % (', '.join(names[:-1]), names[-1])
    else:
        return '%s and %d others like this' % (', '.join(names[:2]), len(names) - 2)
