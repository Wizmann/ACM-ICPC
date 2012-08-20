//Result:Accepted	14984K	204MS	C++	 1875B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 100913

int n,k;

typedef struct node
{
	int f[35];
	int next;
	
	void setnode(int num)
	{
		memset(f,0,sizeof(f));
		for(int i=0;i<k;i++)
		{
			f[i]=num%2;
			num/=2;
		}
		next=-1;
	}
	
	void print()
	{
		for(int i=0;i<k;i++) printf("%d",f[i]);
		printf("-->%d\n",next);
	}
}node;

node array[SIZE];
int hashtable[SIZE];
int a[SIZE];

int equal(int a,int b)
{
	int res=1;
	for(int i=0;i<k;i++)
	{
		if(array[a].f[i]==array[b].f[i]) continue;
		else
		{
			res=0;
			break;
		}
	}
	return res;
}

int hash(int *a)
{
	int res=0;
	for(int i=0;i<k;i++)
	{
		res= ( (991 ^ (res<< 3) ) + (a[i] >> 4)) ^ (a[i] << 5);		
	}
	res%=SIZE;
	if(res<0) res+=SIZE;
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	memset(hashtable,-1,sizeof(hashtable));
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			array[i].f[j]+=array[i-1].f[j]+a[i]%2;
			a[i]/=2;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<k;j++)
		{
			array[i].f[j]-=array[i].f[0];
		}	
		array[i].f[0]=0;
	}	

	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int pos=hash(array[i].f);
		
		if(hashtable[pos]==-1) hashtable[pos]=i;
		else
		{
			int settle=0;
			pos=hashtable[pos];
			
			if(pos!=-1&&equal(i,pos))
			{
				//printf("%d %d\n",i,pos);
				if(ans<abs(i-pos)) ans=abs(i-pos);
				settle=1;
			}
			while(pos==-1)
			{
				pos=array[pos].next;
				if(pos!=-1&&equal(i,pos))
				{
					if(ans<abs(i-pos))
					{
						ans=abs(i-pos);
						//printf("%d %d\n",i,pos);
					}
					settle=1;
				}
			}
			if(!settle)
			{
				pos=hash(array[i].f);
				array[i].next=hashtable[pos];
				hashtable[pos]=i;
			}
		}	
	}	
	printf("%d\n",ans);			
	return 0;
}
		

