class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        switch (n) {
            case 1: return 0;
            case 2: return 1;
            default:
                return _fib(n, 0, 1, 3);
        }
    }
private:
    int _fib(int n, int a, int b, int cur) {
        if (cur == n) {
            return a + b;
        } else {
            return _fib(n, b, a + b, cur + 1);
        }
    }
};

