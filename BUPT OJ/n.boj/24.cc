#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct node
{
	int st,end;
}node;

node stree[100000*4];
int array[100100];
int seq[30][100100];
int a,b,k;
int ti=1;

inline int left (int a){return 2*a;}
inline int right(int a){return 2*a+1;}

void init(int pos,int st,int end,int deep)
{
	stree[pos].st=st;
	stree[pos].end=end;
	if(st==end)
	{
		seq[deep][st]=array[st];
		return;
	}

	int mid=(st+end)>>1;
	init(left(pos),st,mid,deep+1);
	init(right(pos),mid+1,end,deep+1);
	int i=st,j=mid+1,now=st;
	while(i<=mid&&j<=end)
	{
		if(seq[deep+1][i]<=seq[deep+1][j]) seq[deep][now++]=seq[deep+1][i++];
		else seq[deep][now++]=seq[deep+1][j++];
	}
	
	while(j<=end) seq[deep][now++]=seq[deep+1][j++];
	while(i<=mid) seq[deep][now++]=seq[deep+1][i++];
}
	
int cnt(int pos,int value,int deep)
{
	int lft=stree[pos].st,rht=stree[pos].end;
	if(a<=lft&&b>=rht)
	{
		int st=lft,end=rht;
		int mid;
		while(st<=end)
		{
			mid=(st+end)>>1;
			if(seq[deep][mid]<=value) st=mid+1;
			else end=mid-1;
		}
		if(seq[deep][mid]<=value) st=mid;
		else st=mid-1;
		return st-lft+1;
	}
	int res=0;
	if(lft==rht) return 0;
	if(a<=stree[left(pos)].end) res+=cnt(left(pos),value,deep+1);
	if(b>=stree[right(pos)].st) res+=cnt(right(pos),value,deep+1);
	return res;
}
			


int main()
{
	
	freopen("input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:\n",ti++);
		//memset(array,0,sizeof(array));
		memset(stree,0,sizeof(stree));
		memset(seq,0,sizeof(seq));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&array[i]);
		init(1,1,n,1);
		int ask;
		scanf("%d",&ask);
		while(ask--)
		{
			scanf("%d%d",&a,&b);
			k=(b-a)/2+1;
			//printf("k==%d\n",k);
			int res,temp;
			int st=1,end=n;
			while(st<=end)
			{
				res=(st+end)>>1;
				temp=cnt(1,seq[1][res],1);
				if(temp>=k) end=res-1;
				else st=res+1;
			}
			if(temp>=k) temp=res;
			else st=res+1;
			printf("%d\n",seq[1][st]);
		}
		printf("\n");
	}
	return 0;
}
