public class SumOfConsecutiveIntegers
{
    public static int Position(int x, int y, int n)
    {
        if (y % x == 0) {
            int mid = y / x;
            int start = mid - x / 2;
            return start + n;
        } else {
             int mid = y / (x / 2);
            int start = (mid + 1) / 2 - x / 2;
            return start + n;
        }
    }
}
