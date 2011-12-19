#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 24

char matrix[N][N];

void matrixdraw(int x,int y,int *sum)
{
	if(matrix[y][x]=='w') (*sum)++;

	matrix[y][x]='s';
	if(x+1<N  &&matrix[y][x+1]!='s' &&matrix[y][x+1]!='b'  &&matrix[y][x+1]!='#')  matrixdraw(x+1,y,sum);
	if(x-1>=0 &&matrix[y][x-1]!='s' &&matrix[y][x-1]!='b'  &&matrix[y][x-1]!='#')  matrixdraw(x-1,y,sum);
	if(y+1<N  &&matrix[y+1][x]!='s' &&matrix[y+1][x]!='b'  &&matrix[y+1][x]!='#')  matrixdraw(x,y+1,sum);
	if(y-1>=0 &&matrix[y-1][x]!='s' &&matrix[y-1][x]!='b'  &&matrix[y-1][x]!='#')  matrixdraw(x,y-1,sum);

}

void print()
{
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<N;k++) printf("%c ",matrix[i][k]);
		printf("\n");
	}
}

int main()
{
	
	//freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	scanf("\n");
	for(int i=0;i<n;i++)
	{
		int w=0;
		int xs,ys;
		int score=0;
		for(int k=0;k<N;k++)
		{
			for(int l=0;l<N;l++)
			{
				scanf("%c",&matrix[k][l]);
				if(matrix[k][l]=='w') w++;
				else if(matrix[k][l]=='s')
				{
					xs=l;ys=k;
				}
			}
			scanf("\n");				
		}
		matrixdraw(xs,ys,&score);
		
		//printf("%d==%d\n",w,score);
		
		//print();
		
		if(score==w) printf("YES");
		else printf("NO");
		
		printf("\n");
	}
	return 0;
}