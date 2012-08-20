//Result:wizmann	1870	Accepted	712K	454MS	G++	1366B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

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

void slove(int nr,int& ans_x,int& ans_y)
{
	int layer=0;
	for(int i=0;i<SIZE;i++)
	{
		if(num[i]>nr)
		{
			layer=i;
			break;
		}
	}
	nr-=num[layer-1];
	int dir=nr/layer;//每一层蜂巢都有六个方向，以(0,layer)为开始点，
						//每一个方向有layer个点
	int pos=nr%layer;//在每一个方向的layer个点上，不同的点的位置决定了它的坐标
	if(dir==1){ans_x=-pos;ans_y=layer;}
	elif(dir==2){ans_x=-layer;ans_y=layer-pos;}
	elif(dir==3){ans_x=-layer+pos;ans_y=-pos;}
	elif(dir==4){ans_x=pos;ans_y=-layer;}
	elif(dir==5){ans_x=layer;ans_y=-layer+pos;}
	elif(dir==0)
	{
		ans_x=layer-pos;ans_y=pos;
		if(nr==0) ans_x--;
	}
}

int main()
{
	//freopen("a.txt","r",stdin);
	int a,b;
	int ax,bx,ay,by;
	init();
	while(input(a>>b) && a+b)
	{
		int dis;
		slove(a,ax,ay);
		slove(b,bx,by);
		ax-=bx;ay-=by;
		//在蜂巢坐标模型中，每一个点对应有六个方向
		//0 1
		//-1 1
		//-1 0
		//0 -1
		//1 -1
		//1 0
		//所有以如下的计算步数的公式
		if(ax*ay>0) dis=abs(ax+ay);
		else dis=max(abs(ax),abs(ay));
		printf("The distance between cells %d and %d is %d.\n",a,b,dis);
	}
	return 0;
}

