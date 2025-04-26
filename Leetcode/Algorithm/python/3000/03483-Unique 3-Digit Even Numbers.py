class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        valid_numbers = set()
        for perm in permutations(digits, 3):
            a, b, c = perm
            if a == 0:
                continue  # 前导零
            if c % 2 != 0:
                continue  # 不是偶数
            num = 100 * a + 10 * b + c
            valid_numbers.add(num)
        return len(valid_numbers)
