#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <iostream>

using namespace std;

typedef struct cmd
{
	int a,b;
	char type[5];
	
	void setcmd()
	{
		scanf("%d%s%d",&a,type,&b);
	}
}cmd;

cmd array[55];

int main()
{
	freopen("input.txt","r",stdin);
	int n,ask;
	while(scanf("%d%d",&n,&ask),n,ask)
	{
		 memset(array,0,sizeof(array));
		 for(int i=0;i<ask;i++) array[i].setcmd();
		 
		 int flag;
		 for(int i=0;i<1<<n;i++)
		 {
			 flag=1;
			 bitset<15> bs(i);
			 for(int i=0;i<ask;i++)
			 {
				 if(*array[i].type=='a')
				 {
					 if(bs[array[i].a-1]&&bs[array[i].b-1]) /*Do Nothing*/;
					 else
					 {
						 flag=0;break;
					 } 
				 }
				 else if(*array[i].type=='o')
				 {
					 if(bs[array[i].a-1]||bs[array[i].b-1]) /*Do Nothing*/;
					 else
					 {
						 flag=0;break;
					 }
				 }
				 else
				 {
					 if(bs[array[i].a-1]&&bs[array[i].b-1])
					 {
						 flag=0;break;
					 }
					 else
					 {
						 if(bs[array[i].a-1]||bs[array[i].b-1]) /*Do Nothing*/;
						 else
						 {
							 flag=0;break;
						 }
					 }
				 }
			 }
			 if(flag)
			 {
				 if(bs[0]) printf("on");
				 else printf("off");
				 for(int i=1;i<n;i++)
				 {
					 if(bs[i]) printf(" on");
					 else printf(" off");
				 }
				 printf("\n");
				 break;
			 }
		 }
		if(flag!=1) printf("No solution\n");
	 
	 }
	 return 0;
}
		
