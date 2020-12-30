class Solution {
	func hIndex(citations: [Int]) -> Int {
		var ans = 0
		for (index, element) in citations.sort().reverse().enumerate() {
			if element >= index + 1 {
				ans = index + 1
			}
		}
		return ans
	}
}