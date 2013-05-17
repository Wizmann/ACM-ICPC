#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

class Solution 
{
public:
    vector<string> restoreIpAddresses(string s) 
    {
        ips.clear();
        vector<int> v;
        solve(s.c_str(),v);
        return ips;
    }
    vector<string> ips;

    void solve(const char *s,vector<int>& v)
    {
        if(*s=='\0' && v.size()==4)
        {
            char t[256];
            sprintf(t,"%d.%d.%d.%d",v[0],v[1],v[2],v[3]);
            ips.push_back(string(t));
        }
        else if(v.size()==4) return;
        else
        {
            if(*s=='0')
            {
                v.push_back(0);
                solve(s+1, v);
                v.pop_back();
            }
            else
            {
                int x=0;
                for(int i=0;i<3 && s[i];i++)
                {
                    x = x*10 + *(s+i)-'0';
                    v.push_back(x);
                    if(x<=255) solve(s+i+1, v);
                    v.pop_back();
                }
            }
        }
    }
};

int main()
{
    Solution S;
    vector<string> v=S.restoreIpAddresses("2551234512");
    for(int i=0;i<(int)v.size();i++)
    {
        print(v[i]);
    }
    return 0;
}
