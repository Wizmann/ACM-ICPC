class Solution {
public:
    bool isPalindrome(int x) {
  	if (x < 0) {
			return false;
		}
		
		int l = 0, r = int_length(x) - 1;
		while (l <= r) {
			if (get_digit(x, l) != get_digit(x, r)) {
				return false;
			}
			l++; r--;
		}
		return true;
	}		
		
	int int_length(int x)
	{
		if (x == 0) {
			return 1;
		}
		int res = 0;
		while(x) {
			x /= 10;
			res++;
		}
		return res;
	}
	
	int get_digit(int val, int x) {
		for (int i = 0; i < x; i++) {
			val /= 10;
		}
		return val % 10;
	}
};
