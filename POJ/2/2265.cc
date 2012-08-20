//Result:wizmann	2265	Accepted	700K	0MS	G++	1012B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100
#define elif else if

int num[SIZE];

void init()
{
	for(int i=0;i<SIZE;i++)
	{
		num[i]=3*i*i+3*i+1;
	}
}

int main()
{
	int x,ans_x,ans_y;
	init();
	while(scanf("%d",&x)!=EOF && x)
	{
		int layer=-1;
		for(int i=0;i<SIZE;i++)
		{
			if(x<num[i])
			{
				layer=i;
				break;
			}
		}
		x-=num[layer-1];
		int dir=x/layer;//每一层蜂巢都有六个方向，以(0,layer)为开始点，
						//每一个方向有layer个点
		int pos=x%layer;//在每一个方向的layer个点上，不同的点的位置决定了它的坐标
		if(dir==1){ans_x=-pos;ans_y=layer;}
		elif(dir==2){ans_x=-layer;ans_y=layer-pos;}
		elif(dir==3){ans_x=-layer+pos;ans_y=-pos;}
		elif(dir==4){ans_x=pos;ans_y=-layer;}
		elif(dir==5){ans_x=layer;ans_y=-layer+pos;}
		elif(dir==0)
		{
			ans_x=layer-pos;ans_y=pos;
			if(x==0) ans_x--;
		}
		printf("%d %d\n",ans_x,ans_y);
	}
	return 0;
}
