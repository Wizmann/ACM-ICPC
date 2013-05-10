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
    bool isPalindrome(string s)
    {
        string p;
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            char x = alpha(s[i]);
            if(x!=-1) p+=x;
        }
        string r = reverse(p);
        return p == r;
    }

    string reverse(string s)
    {
        int l = s.length();
        string r;
        for(int i = l-1;i >= 0;i--) r+=s[i];
        return r;
    }

    char alpha(char x)
    {
        if((x>='a' && x<='z') || (x>='0' && x<='9')) return x;
        else if(x>='A' && x<='Z') return x^32;
        else return -1;
    }
};


int main()
{
    Solution S;
    print(S.isPalindrome("a ba"));
    return 0;
}
