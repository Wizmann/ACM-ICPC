class Solution(object):
    def validUtf8(self, data):
        data = data[::-1]
        while data:
            x = data.pop()
            z = self.leading_zero(x)

            if z == -1 or z == 1 or z > 4:
                return False

            if z == 0:
                continue
            z -= 1

            xs, data = data[-z:], data[:-z]
            if len(xs) != z:
                return False

            for item in xs:
                if self.leading_zero(item) != 1:
                    return False
        return True

    def leading_zero(self, num):
        s = '{:08b}'.format(num)
        return s.find('0')
