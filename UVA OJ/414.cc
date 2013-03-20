//Result:414	Machined Surfaces	Accepted	C++	0.008	2013-03-20 12:09:25
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int INF = 1<<28;
const int SIZE = 1024;


char str[SIZE];
int array[SIZE];
int n;

int main()
{
    freopen("input.txt","r",stdin);
    while(input(n) and n)
    {
        int mini=INF;
        for(int i=0;i<n;i++)
        {
            while(true)
            {
                gets(str);
                if(str[0] && str[0]!='\n' && str[0]!='\r') break;
            }
            //print(str);
            int B=0;
            for(int j=0;str[j];j++)
            {
                if(str[j]==' ') B++;
            }
            array[i]=B;
            mini = min(mini, B);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += array[i]-mini;
        }
        print(ans);
    }
    return 0;
}



