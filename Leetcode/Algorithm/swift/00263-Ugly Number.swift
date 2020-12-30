class Solution {
	func isUgly(num: Int) -> Bool {
		if num == 0 {
			return false
		}
		
		var x = num
		
		while x % 2 == 0 {
			x /= 2
		}
		while x % 3 == 0 {
			x /= 3
		}
		while x % 5 == 0 {
			x /= 5
		}
		return x == 1
	}
}