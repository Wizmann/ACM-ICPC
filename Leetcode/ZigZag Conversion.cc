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
    string convert(const string& s, int nRows)
    {
        if(nRows<2) return s;
        int l = s.length();
        int sz = nRows*2 -2;

        string res;

        for(int i=0;i<nRows;i++)
        {
            for(int j=0;j*sz<l;j++)
            {
                if(i==0 || i==nRows-1)
                {
                    if(j*sz+i<l) res += s[j*sz+i];
                }
                else
                {
                    if(j*sz+i<l) res += s[j*sz+i];
                    if((j+1)*sz-i<l) res += s[(j+1)*sz-i];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution S;
    print(S.convert("PAYPALISHIRING",4));
    print("PINALSIGYAHRPI");
    return 0;
}
