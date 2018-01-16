// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int N, int M) {
        int g = gcd(N, M);
        long res = Long.valueOf(N) / Long.valueOf(g);
        return Math.toIntExact(res);
    }
    
    public int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }
}
