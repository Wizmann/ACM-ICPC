//Result:3771198	 May 26, 2013 2:44:14 PM	Wizmann	 C - Ivan and Powers of Two	 GNU C++	Accepted	187 ms	3240 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 102400;

int n;

int main()
{
    freopen("input.txt","r",stdin);
    int a;
    while(input(n))
    {
        map<int, int> top;
        for(int i=0;i<n;i++)
        {
            input(a);
            top[a]++;
        }
        int ans = 0, pre = -1;
        for(map<int, int>::iterator iter=top.begin();
             iter!=top.end(); iter++)
        {
            int i = iter->first;
            if(top[i]/2) 
            {
                top[i+1] += top[i]/2;
                top[i] = top[i]%2;
            }
            
            if(top[i])
            {
                ans += i - pre - 1;
                pre = i;
            }
        }
        print(ans);
    }
    return 0;
}
    
    
