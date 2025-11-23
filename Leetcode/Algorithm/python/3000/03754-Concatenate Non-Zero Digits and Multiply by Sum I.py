class Solution(object):
    def sumAndMultiply(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Convert the number to a string to iterate through each digit
        str_n = str(n)
        
        # Extract non-zero digits and form the new number x
        x_str = ""
        for char in str_n:
            if char != '0':
                x_str += char
        
        # If no non-zero digits were found, x is 0
        if x_str == "":
            x = 0
        else:
            x = int(x_str)
        
        # Calculate the sum of the digits in x
        digit_sum = 0
        temp_x = x
        while temp_x > 0:
            digit_sum += temp_x % 10
            temp_x //= 10
        
        # Return the product of x and the sum of its digits
        return x * digit_sum
