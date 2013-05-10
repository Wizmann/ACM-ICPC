class Solution {
public:
    double pow(double x, long long n)
    {
        if(n>=0) return _pow(x, n, 1.0);
        else return 1./_pow(x, -n, 1.0);
    }
    double _pow(double x, long long n, double res)
    {
        if(n==0) return 1.0 * res;
        else if(n==1) return x * res;
        else
        {
            if(n&1) return _pow(x*x, n>>1, res*x);
            else return _pow(x*x, n>>1, res);
        }
    }
};