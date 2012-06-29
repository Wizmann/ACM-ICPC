//Result:wizmann	3185	Accepted	728K	0MS	G++	1762B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20

/*
 * 先用高斯消元法求出正确解，然后通过穷举自由元dfs求出最优解
 */

int mat[SIZE+5][SIZE+5];
int ptr;
int ans[SIZE],x[SIZE];
int tmp_mat[SIZE+5][SIZE+5];

void init()
{
	for(int i=0;i<SIZE;i++)
	{
		if(i-1>=0) mat[i][i-1]=1;
		mat[i][i]=1;
		if(i+1<SIZE) mat[i][i+1]=1;
	}
}

int dfs(int v)
{
	if(v==20)
	{
		int temp=0;  
        for(int i=0;i<SIZE;i++) x[i]=ans[i];  
        memcpy(tmp_mat,mat,sizeof(mat));
        for(int i=ptr-1;i>=0;i--)
		{  
			for(int j=i+1;j<20;j++)
			{
				tmp_mat[i][SIZE]^=(x[j]&tmp_mat[i][j]);  
			}
			x[i]=tmp_mat[i][SIZE];  
        }  
        for(int i=0;i<SIZE;i++)
        {
            if(x[i]) temp++;  
		}
        return temp;  
    }
    ans[v]=0;  
    int res=dfs(v+1);  
    ans[v]=1;  
    res=min(res,dfs(v+1));  
    return res;
} 


int gauss()
{
	for(int row=0,col=0;row<SIZE&&col<SIZE;col++)
	{
		int zptr=-1;
		for(int i=row;i<SIZE;i++)
		{
			if(mat[i][col])
			{
				zptr=i;
				break;
			}
		}
		if(zptr==-1)
		{
			//print(col);
			continue;
		}
		for(int i=0;i<=SIZE;i++)
		{
			swap(mat[row][i],mat[zptr][i]);
		}

		for(int i=0;i<SIZE;i++) if(i!=row)
		{
			if(!mat[i][col]) continue;
			for(int j=0;j<=SIZE;j++)
			{
				mat[i][j]^=mat[row][j];
			}
		}
		row++;
		ptr=row;
	}
	if(ptr==SIZE) 
	{
		int ans=0;
		for(int i=0;i<SIZE;i++)
		{
			if(mat[i][SIZE]) ans++;
		}
		return ans;
	}
	else return dfs(ptr);
}



int main()
{
	int a;
	init();
	for(int i=0;i<SIZE;i++)
	{
		input(a);
		mat[i][SIZE]=a;
	}
	print(gauss());
	return 0;
}
