class Solution {
public:
    int trailingZeroes(int n) {
        int u = get_five(n);
        int v = get_two(n);
        
        return min(u, v);
    }
private:
	int get_five(int n) {
		return get_number(n, 5);
	}
	
	int get_two(int n) {
		return get_number(n, 2);
	}
private:
	int get_number(int n, int u) {
		int res = 0;
		while (n) {
			res += n / u;
			n /= u;
		}
		return res;
	}
};
