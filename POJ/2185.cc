//Result:wizmann	2185	Accepted	2252K	1016MS	G++	1076B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define X 80
#define Y 10010

char ga[Y][X];
char gb[X][Y];

int c,r;

int get_next(char *g)
{
	int next[X];
	next[0]=-1;
	int i=0,j=-1;
	int col=strlen(g);
	while(i<col)
	{
		if(j==-1 || g[i]==g[j])
		{
			i++;j++;
			next[i]=j;
		}
		else j=next[j];
	}
	return i-next[i];
}

int GCD(int a,int b)
{
	if(a<b) return GCD(b,a);
	else
	{
		if(a%b==0) return b;
		else return GCD(b,b%a);
	}
}

int LCM(int a,int b)
{
	return a*b/GCD(a,b);
}


int main()
{
	while(input(r>>c))
	{
		for(int i=0;i<r;i++)
		{
			input(ga[i]);
			for(int j=0;ga[i][j];j++)
			{
				gb[j][i]=ga[i][j];
			}
		}
		int ans_c,ans_r;
		ans_c=ans_r=1;
		for(int i=0;i<r;i++)
		{
			ans_c=LCM(ans_c,get_next(ga[i]));
		}
		for(int i=0;i<c;i++)
		{
			ans_r=LCM(ans_r,get_next(gb[i]));
		}

		print(ans_c*ans_r);
	}
	return 0;
}
	
