class Solution 
{
public:
    int sqrt(long long x) 
    {
        unsigned long long l=0, r=x;
        while(l<=r)
        {
            long long mid = (l+r)>>1;
            if(mid * mid <= x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};