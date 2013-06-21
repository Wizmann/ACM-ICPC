#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

class Solution 
{
public:
    int reverse(int x) 
    {
        char s[1024];
        bool flag = true;
        if(x<0)
        {
            x=-x;
            flag=false;
        }
        sprintf(s,"%d", x);
        int l = 0, r = strlen(s)-1;
        while(l<r)
        {
            swap(s[l],s[r]);
            l++;r--;
        }
        return (flag?1:-1) * atoi(s);
    }
};

int main()
{
    Solution S;
    print(S.reverse(0));
    return 0;
}
