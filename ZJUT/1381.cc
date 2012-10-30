//Result:Wizmann	1381	Accepted	281MS	4316K	661B	G++	2012-10-30 11:41:29
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

int dp[SIZE][SIZE];
char A[SIZE],B[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%s%s",A,B)!=EOF)
	{
		int lena=strlen(A);
		int lenb=strlen(B);
		
		for(int i=0;i<=lena;i++) dp[i][0]=i;
		for(int i=0;i<=lenb;i++) dp[0][i]=i;
		
		for(int i=1;i<=lena;i++)
		{
			for(int j=1;j<=lenb;j++)
			{
				dp[i][j]=min(min(1+dp[i-1][j],1+dp[i][j-1]),
								dp[i-1][j-1]+(A[i-1]==B[j-1]?0:1));
			}
		}
		print(dp[lena][lenb]);
	}
	return 0;
}

	
