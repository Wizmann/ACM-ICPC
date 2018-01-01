/**
*   Return the second largest number in the array.
*   @param {Number[]} nums - An array of numbers.
*   @return {Number} The second largest number in the array.
**/
function getSecondLargest(nums) {
    nums.sort(function(a, b) {
        return parseInt(a) - parseInt(b);
    });
    var n = nums.length;
    for (var i = n - 1; i >= 0; i--) {
        if (nums[i] != nums[n - 1]) {
            return nums[i];
        }
    }
    return NaN;
}
