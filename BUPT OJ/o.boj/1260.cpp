#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **creat(int n)
{
	int **ret=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	{
		ret[i]=(int*)malloc(sizeof(int)*n);
	}
	return ret;
}

void print(int **mat,int n)
{
	for(int y=0;y<n;y++)
	{
		for(int x=0;x<n;x++)
		{
			if(mat[y][x]==-1) 
			{
				if(x==0) printf(" ");
				else printf("  ");
			}
			else
			{
				if(x==0) printf("%d",mat[y][x]);
				else printf(" %d",mat[y][x]);
			}
		}
		printf("\n");
	}
}

/*void print(int **mat,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d\t",mat[i][j]);
		printf("\n");
	}
}*/

void ins(int **mat,int *array,int n)
{
	int *p=array;int i=1;
	for(int x=0;x<n;x++)
	{		
		for(int y=0;y<n;y++)
		{
			if(y>=i) break;
			mat[y][x]=*(p++);	
		}
		i+=1;
	}
}

void make(int n,int s,int *array)
{
	int *p=array;
	for(int i=s;i<s+n*(n+1)/2;i++)
	{
		if(i<10) *(p++)=i;
		else
		{
			int temp=i%9;
			if(temp==0) *(p++)=9;
			else *(p++)=i%9;
		}
	} 
}

void set(int **mat,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) mat[i][j]=-1;
	}
}


int main()
{
	int array[500];
	int N,S;
	scanf("%d%d",&N,&S);
	make(N,S,array);
	int** matrix=creat(N);
	set(matrix,N);
	ins(matrix,array,N);
	print(matrix,N);
	return 0;
}

//int **creat(int n)
//void ins(int **mat,int *array,int n)
//void print(int **mat,int n)