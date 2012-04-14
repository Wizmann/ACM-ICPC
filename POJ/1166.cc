//Result:wizmann	1166	Accepted	704K	438MS	G++	1455B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

bool move[10][10]={
    //A B C D E F G H I
     {0,0,0,0,0,0,0,0,0},
     {1,1,0,1,1,0,0,0,0},
     {1,1,1,0,0,0,0,0,0},
     {0,1,1,0,1,1,0,0,0},
     {1,0,0,1,0,0,1,0,0},
     {0,1,0,1,1,1,0,1,0},
     {0,0,1,0,0,1,0,0,1},
     {0,0,0,1,1,0,1,1,0},
     {0,0,0,0,0,0,1,1,1},
     {0,0,0,0,1,1,0,1,1},
};

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	int status=0;
	for(int i=0;i<9;i++)
	{
		scanf("%d",&t);
		status |= t<<(i<<1);
	}
	int mv[10];
	for(mv[1]=0;mv[1]<4;mv[1]++)
	for(mv[2]=0;mv[2]<4;mv[2]++)
	for(mv[3]=0;mv[3]<4;mv[3]++)
	for(mv[4]=0;mv[4]<4;mv[4]++)
	for(mv[5]=0;mv[5]<4;mv[5]++)
	for(mv[6]=0;mv[6]<4;mv[6]++)
	for(mv[7]=0;mv[7]<4;mv[7]++)
	for(mv[8]=0;mv[8]<4;mv[8]++)
	for(mv[9]=0;mv[9]<4;mv[9]++)
	{
		int nows=status;
		for(int i=1;i<=9;i++)
		{
			for(int j=0;j<mv[i];j++)
			{
				int ns=0;
				for(int k=0;k<9;k++)
				{
					int t=((3<<(k<<1)) & nows) >> (k<<1);
					//print(t);
					if(move[i][k]) t=(t+1)%4;
					ns |= t<<(k<<1);
				}
				nows=ns;
			}
		}
		
		if(nows==0) goto suc;
	}

suc:bool flag=true;
	for(int i=1;i<=9;i++)
	{
		if(mv[i])
		{
			for(int j=0;j<mv[i];j++)
			{
				if(flag)
				{
					printf("%d",i);
					flag=false;
				}
				else printf(" %d",i);
			}
		}
	}
	puts("");
	return 0;
}


