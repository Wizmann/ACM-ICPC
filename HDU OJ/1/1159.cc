//Result:2012-10-30 12:03:56	Accepted	1159	46MS	2320K	786 B	G++	Wizmann

//测试地址：http://acm.hdu.edu.cn/showproblem.php?pid=1159

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

char A[SIZE],B[SIZE];
int dp[SIZE][SIZE];

int main()
{
	while(scanf("%s%s",A,B)!=EOF)
	{
		int lena=strlen(A);
		int lenb=strlen(B);

		for(int i=0;i<=lena;i++) dp[i][0]=0;
		for(int j=0;j<=lenb;j++) dp[0][j]=0;

		for(int i=1;i<=lena;i++)
		{
			for(int j=1;j<=lenb;j++)
			{
				if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}

		print(dp[lena][lenb]);
	}
	return 0;
}

