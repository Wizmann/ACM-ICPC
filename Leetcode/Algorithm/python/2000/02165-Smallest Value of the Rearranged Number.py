#coding=utf-8
#python3

class Solution:
    def smallestNumber(self, num: int) -> int:
        if num > 0:
            num = sorted(map(int, str(num)))
            cnt = 0
            while num and num[0] == 0:
                cnt += 1
                num.pop(0)
            return int(''.join(map(str, [num[0]] + [0] * cnt + num[1:])))
        else:
            num = sorted(map(int, str(-num)), reverse=True)
            return int('-' + ''.join(map(str,num)))
        

'''
^^^TEST^^^
3100
----
1003
$$$TEST$$$

^^^TEST^^^
-123
----
-321
$$$TEST$$$
'''
