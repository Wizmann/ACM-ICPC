/*
A - Sorting Slides
Time Limit:1000MS     Memory Limit:10000KB     64bit IO Format:%I64d & %I64u
Submit
 
Status
 
Practice
 
POJ 1486
Appoint description: 
Description
Professor Clumsey is going to give an important talk this afternoon. Unfortunately, he is not a very tidy person and has put all his transparencies on one big heap. Before giving the talk, he has to sort the slides. Being a kind of minimalist, he wants to do this with the minimum amount of work possible. 

The situation is like this. The slides all have numbers written on them according to their order in the talk. Since the slides lie on each other and are transparent, one cannot see on which slide each number is written. 


Well, one cannot see on which slide a number is written, but one may deduce which numbers are written on which slides. If we label the slides which characters A, B, C, ... as in the figure above, it is obvious that D has number 3, B has number 1, C number 2 and A number 4. 

Your task, should you choose to accept it, is to write a program that automates this process.
Input
The input consists of several heap descriptions. Each heap descriptions starts with a line containing a single integer n, the number of slides in the heap. The following n lines contain four integers xmin, xmax, ymin and ymax, each, the bounding coordinates of the slides. The slides will be labeled as A, B, C, ... in the order of the input. 

This is followed by n lines containing two integers each, the x- and y-coordinates of the n numbers printed on the slides. The first coordinate pair will be for number 1, the next pair for 2, etc. No number will lie on a slide boundary. 

The input is terminated by a heap description starting with n = 0, which should not be processed. 
Output
For each heap description in the input first output its number. Then print a series of all the slides whose numbers can be uniquely determined from the input. Order the pairs by their letter identifier. 

If no matchings can be determined from the input, just print the word none on a line by itself. 

Output a blank line after each test case. 
Sample Input
4
6 22 10 20
4 18 6 16
8 20 2 18
10 24 4 8
9 15
19 17
11 7
21 11
2
0 2 0 2
0 2 0 2
1 1
1 1
0
Sample Output
Heap 1
(A,4) (B,1) (C,2) (D,3)

Heap 2
none
*/


/*
题目的大意比较难叙述清楚。大概是，有一些幻灯片，上面都写上了编号，但是它们现在混在了一起。由于幻灯片是透明的，所以不知道哪个编号是哪张幻灯片的。现在给出一些坐标信息，让你确定哪些编号是可以对应得上幻灯片的，并输出之。

如果建立二分匹配的模型来做，那么也就是说这些边是二分匹配的必须边，删掉这些边后，匹配就会不成功。因此给出了一种做法：这道题要先计算出最大匹配数,并把最大匹配表记录下来,然后把匹配到的边记录在队列里,然后依次删除,重新计算匹配数,如果匹配数减少说明此边是必须也是唯一的.如果一样说明这边存不存在都行,要从原来记录的最大匹配表中减掉此边.
*/


//Result:wizmann	1486	Accepted	752K	0MS	G++	2299B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32

int n;

struct Cpoint
{
	int x,y;
	Cpoint(){}
	Cpoint(int ix,int iy)
	{
		x=ix;y=iy;
	}
};

struct Cslide
{
	int xmin,xmax;
	int ymin,ymax;
	Cslide(){}
	Cslide(int ixmin,int ixmax,int iymin,int iymax)
	{
		xmin=ixmin;xmax=ixmax;
		ymin=iymin;ymax=iymax;
	}
	
	bool inSlide(const Cpoint &p)
	{
		if(p.x>=xmin && p.x<=xmax &&
			p.y>=ymin && p.y<=ymax) return true;
		else return false;
	}
};

Cslide slide[SIZE];
int g[SIZE][SIZE];
char visit[SIZE];
int pre[SIZE];
pair<int,int> edge[SIZE];

bool deal(int x)
{
	for(int i=0;i<n;i++) if(g[x][i])
	{
		if(!visit[i])
		{
			visit[i]=1;
			if(pre[i]==-1 || deal(pre[i]))
			{
				pre[i]=x;
				return true;
			}
		}
	}
	return false;
}
				
			

int hungary()
{
	int sum=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(deal(i)) sum++;
	}
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b,c,d;
	int cas=1;
	while(input(n) && n)
	{
		printf("Heap %d\n",cas++);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			slide[i]=Cslide(a,b,c,d);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			for(int j=0;j<n;j++)
			{
				if(slide[j].inSlide(Cpoint(a,b)))
				{
					g[j][i]=1;
				}
			}
		}
		int ind=0;
		int sum=hungary();
		//print(sum);
		for(int i=0;i<n;i++)
		{
			if(pre[i]!=-1)
			{
				edge[ind++]=make_pair(i,pre[i]);
			}
		}
		ind=0;
		pair<int,int> ans[SIZE];
		for(int i=0;i<sum;i++)
		{
			g[edge[i].second][edge[i].first]=0;
			int t=hungary();
			if(t!=sum)
			{
				//print(edge[i].second<<' '<<edge[i].first);
				ans[ind++]=make_pair(edge[i].second,edge[i].first);
			}
			g[edge[i].second][edge[i].first]=1;
		}
		if(ind==0) puts("none");
		else
		{
			sort(ans,ans+ind);
			for(int i=0;i<ind;i++)
			{
				if(i) printf(" ");
				printf("(%c,%d)",'A'+ans[i].first,ans[i].second+1);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}





