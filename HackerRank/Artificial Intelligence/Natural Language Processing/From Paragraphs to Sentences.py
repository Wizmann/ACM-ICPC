import sys

sys.stdin = open('a.txt')

#states
QUOTE = 0
ABBR = 1
NORMAL = 2

buffer = []
state = NORMAL
abbr_cnt = 0
pre = " "

passage = raw_input()

for char in passage:
    if char.isspace() and not buffer:
        pre = char
        continue
    buffer.append(char)
    
    if state == QUOTE and char not in "\"\'":
        continue
        
    if state == ABBR:
        abbr_cnt += 1
        
    if abbr_cnt >= 5:
        state = NORMAL
        abbr_cnt = 0
    
    if char.isupper() and len(buffer) == 1:
        pass
    elif char.isupper():
        state = ABBR
    elif char in "\"\'":
        if state == NORMAL and pre == " ":
            state = QUOTE
        elif state == QUOTE:
            state = NORMAL
    elif char == " ":
        if state == ABBR:
            state = NORMAL
            abbr_cnt = 0
    elif char in ".!?":
        if state in [ABBR, QUOTE]:
            pass
        elif state == NORMAL:
            print ''.join(buffer).strip()
            buffer = []
            state = NORMAL
            abbr_cnt = 0
    #print char, state
    pre = char
    
