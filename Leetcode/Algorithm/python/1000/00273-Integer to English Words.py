x = 'Zero One Two Three Four Five Six Seven Eight Nine'.split()
_x = 'Ten Eleven Twelve Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen'.split()
xx = 'Zero Ten Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety'.split()
xxx = [''] + 'Thousand Million Billion'.split()

class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        
        if num == 0:
            return 'Zero'
        
        res = ''
        i = 0
        while num:
            u = num % 1000
            num /= 1000
            v = self.do_num_to_word(u)
            if v:
                v = v + ' ' + xxx[i]
            res = v + ' ' + res
            i += 1
            
        return ' '.join(res.split())
    
    def do_num_to_word(self, num):
        (a, b, c) = map(int, tuple('%03d' % num))
        res = ''
        if a:
            res += x[a] + ' Hundred'
        if b == 1:
            res += ' ' + _x[c]
        else:
            if b:
                res += ' ' + xx[b]
            if c:
                res += ' ' + x[c]
        return res.strip()
        
