//Problem: 2753		User: wizmann
//Memory: 8568K		Time: 563MS
//Language: G++		Result: Accepted
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define llint long long

#define N 500
#define SIZE (N*N)
#define INF 1LL<<60

struct node
{
	bool middle;
	int upper,lower;
	int num;
};

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;
	return ta->num-tb->num;
}

int n,ind;
node array[SIZE];
llint lowersum[SIZE],uppersum[SIZE];

llint getSum(int val,int pos)
{
	llint res=0;
	for(int i=0;i<ind;i++)
	{
		if(array[i].num)
		{
			if(i<pos) res+=array[i].num*array[i].lower;
			else if(i>pos) res+=array[i].num*array[i].upper;
			else res+=val*array[i].num;		
		}
	}
	return res;
}

/*
llint spj(int val,int pos)
{
	//print("SPJ");
	//print("VAL: "<<val<<" POS: "<<pos);
	int i,j;
	for(i=pos-1;!array[i].middle&&i>=0;i--);
	for(j=pos+1;!array[j].middle&&j<ind;j++);
	//print(i<<' '<<j);
	if(j>=ind||(i>=0&&array[pos].num-array[j].num<array[i].num-array[pos].num))
	{
		llint res=getSum(val-1,pos);
		res+=array[i].num;
		return res;
	}
	if(i<0||(j<ind&&array[pos].num-array[i].num>array[j].num-array[pos].num))
	{
		llint res=getSum(val+1,pos);
		res-=array[j].num;
		return res;
	}
	return INF;
}
*/
llint spj(int val,int pos)
{
	llint resa=-INF,resb=-INF,tres;
	if(val-1>=array[pos].lower)
	{
		tres=getSum(val-1,pos);
		for(int i=0;i<pos;i++)
		{
			if(array[i].middle)
			{
				resa=max(resa,tres+array[i].num);
			}
		}
	}
	if(val+1<=array[pos].upper)
	{
		tres=getSum(val+1,pos);
		for(int i=pos+1;i<ind;i++)
		{
			if(array[i].middle)
			{
				resb=max(resb,tres-array[i].num);
			}
		}
	}
	return max(resa,resb);
}	
		

int main()
{
	llint ans;
	while(input(n))
	{
		ans=-INF;
		ind=0;
		memset(array,0,sizeof(array));
		memset(lowersum,0,sizeof(lowersum));
		memset(uppersum,0,sizeof(uppersum));
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				scanf("%d%d%d",&array[ind].num,&array[ind].lower,&array[ind].upper);
				if(i==j)
				{
					array[ind].middle=true;
					array[ind].num*=2;
				}
				else
				{
					array[ind].upper*=2;
					array[ind].lower*=2;
				}
				ind++;
			}
		}
		qsort(array,ind,sizeof(node),cmp);
		for(int i=0;i<ind;i++)
		{
			lowersum[i]=array[i].lower;
			if(i>0) lowersum[i]+=lowersum[i-1];
		}
		for(int i=ind-1;i>=0;i--)
		{
			uppersum[i]=array[i].upper;
			if(i!=ind-1) uppersum[i]+=uppersum[i+1];
		}
		for(int i=0;i<ind;i++)
		{
			llint sum=0-( (i-1>=0?lowersum[i-1]:0)+(i+1<ind?uppersum[i+1]:0) );
			if(sum<=array[i].upper&&sum>=array[i].lower)
			{
				if(sum%2&&!array[i].middle) ans=spj(sum,i);
				else ans=getSum(sum,i);
				break;
			}
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}
