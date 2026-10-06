class Solution(object):
    def validIPAddress(self, IP):
        assert self.is_ipv6("2001:0db8:85a3:0:0:8A2E:0370:7334")
        b4 = self.is_ipv4(IP)
        b6 = self.is_ipv6(IP)
        
        if b4:
            return "IPv4"
        elif b6:
            return "IPv6"
        else:
            return "Neither"
            
    def is_ipv4(self, IP):
        try:
            assert not filter(lambda x: x not in "01234567890.", IP)
            parts = map(int, IP.split("."))
            assert len(parts) == 4
            for part in parts:
                assert 0 <= part <= 255
            assert '.'.join(map(str, parts)) == IP
            return True
        except:
            return False
            
    def is_ipv6(self, IP):
        try:
            IP = IP.lower()
            assert not filter(lambda x: x not in "0123456789abcdefg:", IP)
            parts = map(lambda x: int(x, 16), IP.split(":"))
            assert len(parts) == 8
            parts = IP.split(":")
            for part in parts:
                assert 1 <= len(part) <= 4
                assert 0 <= int(part, 16) <= 0xFFFF
            return True
        except:
            return False
