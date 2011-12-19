//Result:wizmann	2996	Accepted	180K	16MS	C++	1555B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define mp make_pair

struct node
{
	char x,y;
	
	inline void setnode(char a,char b)
	{
		x=a;y=b;
	}
};

char chess[50][50];
char key[][6] = {{'K', 'Q', 'R', 'B', 'N', 'P'}, {'k', 'q', 'r', 'b', 'n', 'p'}};

int main()
{
	freopen("input.txt","r",stdin);
	multimap<char,node> letter;
	multimap<char,node>::iterator iter1,iter2;
	for(int i=16;i>=1;i--) input(chess[i]);
	node pnt;
	
	for(int i=1;i<9;i++)
	{
		for(int j=1;j<9;j++)
		{
			pnt.y=i+'0';
			pnt.x=j-1+'a';
			if(chess[i*2-1][j*4-2]<'Z') letter.insert(mp(chess[i*2-1][j*4-2], pnt));
			pnt.y=9-i+'0',pnt.x =j-1+'a';
			if(chess[17-i*2][j*4-2]>'a') letter.insert(mp(chess[17-i*2][j*4-2], pnt));
		}
	}
	
	for(int j=0;j<2;j++)
	{
		bool first = true;
		for(int i=0;i<6;i++)
		{
			iter1=letter.lower_bound(key[j][i]);
			iter2=letter.upper_bound(key[j][i]);
			while(iter1!=iter2)
			{
				if (first)
				{
					cout<<((!j?"White: ":"Black: "));
					first = false;
				}
				else cout<<",";
				if(i<5) cout<<(char(!j?key[j][i]:(key[j][i] + 'A' - 'a')));
				cout<<(iter1->second).x<<(iter1->second).y;
				iter1++;
			}
		}
		if(!first) print("");
	}
	return 0;
}
