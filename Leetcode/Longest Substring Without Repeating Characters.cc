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
    static const int ALPHA = 26;
    int lengthOfLongestSubstring(string s) 
    {
        int front = 0, rear = 0;
        int l = s.length();
        int hash = 0;
        int ans = 0;
        for(/*pass*/;front<l && rear<l;/*pass*/)
        {
            int now = s[front]-'a';
            if(hash & (1<<now))
            {
                while(true)
                {
                    int pre = s[rear]-'a';
                    hash ^= (1<<pre);
                    rear++;
                    if(pre==now) break;
                }
            }
            hash ^= (1<<now);
            ans = max(ans, front - rear + 1);
            front++;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    print(S.lengthOfLongestSubstring("abcabcbb"));
    print(S.lengthOfLongestSubstring("bbbbbbbb"));
    return 0;
}
