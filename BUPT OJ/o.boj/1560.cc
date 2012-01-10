//Result:1560     Accepted    3835MS    2696K    G++    1575B    2012-01-07 00:22:52    Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 250000
#define N 52

int n;
char dp[SIZE],tmpDp[SIZE];
int diff[SIZE],tmpDiff[SIZE];
int array[N];
int maxPos;

int main()
{
    freopen("input.txt","r",stdin);
    while(input(n))
    {
        memset(dp,0,sizeof(dp));
        memset(diff,0,sizeof(diff));
        memset(array,0,sizeof(array));
        for(int i=0;i<n;i++) scanf("%d",array+i);
        dp[0]=1;
        maxPos=0;
        //我们将设两摞塔的高度为high,low
        //high>=low && high-low=x
        //所以，得到high[x]=high; dp[x]=1;
        for(int i=0;i<n;i++)
        {
            memset(tmpDp,0,sizeof(tmpDp));
            memset(tmpDiff,0,sizeof(tmpDiff));
            for(int j=0;j<=maxPos;j++)
            {
                if(dp[j])//如果有相差为j的两摞塔
                {
                    if(j+array[i]<SIZE)//如果高塔再加上一块
                    {
                        int k=j+array[i];
                        tmpDp[k]=1;
                        maxPos=max(maxPos,k);
                        tmpDiff[k]=max(tmpDiff[k],diff[j]+array[i]);
                    }
                    if(j-array[i]>=0)//向low塔里加上一块，x=high-low=x-array[i]
                    {
                        int k=j-array[i];
                        tmpDp[k]=1;
                        maxPos=max(maxPos,k);
						tmpDiff[k]=max(tmpDiff[k],diff[j]);
                    }
                    if(j-array[i]<0 && diff[j]-j+array[i]<SIZE)
                    //向low塔里加入一块，向low+array[i]>high
                    {
                        int k=array[i]-j;
                        tmpDp[k]=1;
                        maxPos=max(maxPos,k);
						tmpDiff[k]=max(tmpDiff[k],diff[j]+k);
                    }
                }
            }
            for(int i=0;i<=maxPos;i++)//处理最后的结果
            {
                dp[i]= (tmpDp[i]|dp[i]);
                diff[i]=max(diff[i],tmpDiff[i]);
            }
        }
        if(diff[0]>0) print(diff[0]);
        else print(-1);
    }
    return 0;
}

