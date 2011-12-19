#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define mp make_pair
#define pb push_back
#define elif else if

const int mx[]={0,1,0,-1};
const int my[]={-1,0,1,0};

int sum(int k,int st)
{
    int res=0;
    for(int i=0;i<k;i++)
    {
        res+=(st+i);
    }
    return res;
}
        

int main()
{
    int k,m;
    while(input(k>>m))
    {
        int t=0;
        for(int i=1;i<m;i++)
        {
            if(sum(k,i)>m)
            {
                t=i-1;
                break;
            }
        }
        //print("T:"<<t);
        int array[64]={0};
        for(int i=0;i<k;i++)
        {
            array[i]=t+i;
        }
        int minus=m-sum(k,t);
        for(int i=k-1;i>=0;i--)
        {
            if(minus) array[i]++;
            else break;
            minus--;
        }
        for(int i=0;i<k;i++) print(array[i]);
    }
    return 0;
}
