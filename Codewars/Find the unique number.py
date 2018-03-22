def find_uniq(arr):
    a, b = arr[0], arr[1]
    for item in arr[2:]:
        if item == a:
            continue
        elif item == b:
            a, b = b, a
        else:
            b = item
    return b
