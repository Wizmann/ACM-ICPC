class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            int a = n & (1 << i);
            set_bit(res, 32 - i - 1, a);
        }
        return res;
    }
private:
    void set_bit(uint32_t &res, int pos, int u) {
        if (u == 0) {
            res &= (~0u) ^ (1 << pos);
        } else {
            res |= 1 << pos;
        }
    }
}; 
