//Result:Wizmann 	D - Rectangle and Square 	GNU C++ 	Accepted 	30 ms 	1400 KB 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SIZE 8
#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef struct cpoint
{
	int x,y;
	
	void setpoint(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
	
	int distance(const cpoint& cp)
	{
		return (cp.x-x)*(cp.x-x)+(cp.y-y)*(cp.y-y);
	}
}cpoint;

cpoint array[12];

bool checkR(vector<cpoint>& vec)
{
	int num=0;
	set<int> st;
	int sz=vec.size();
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			if(i!=j)
			{
				st.insert(vec[i].distance(vec[j]));

			}
		}
		
		for(int j=0;j<sz;j++)
		{
			if(i!=j)
			{
				for(int k=0;k<sz;k++)
				{
					if(i!=k && j!=k)
					{
						if( vec[i].distance(vec[j])+vec[i].distance(vec[k])==vec[j].distance(vec[k]) ||
							vec[j].distance(vec[i])+vec[j].distance(vec[k])==vec[k].distance(vec[i]) ||
							vec[k].distance(vec[i])+vec[k].distance(vec[j])==vec[i].distance(vec[j]) )
						{
							num++;
						}
					}
				}
			}
		}
	}

	if(num==24 && ( st.size()==3 || st.size()==2 )) return true;
	else return false;
}

bool checkS(vector<cpoint>& vec)
{
	int num=0;
	set<int> st;
	int sz=vec.size();
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			if(i!=j) st.insert(vec[i].distance(vec[j]));
		}
		
		for(int j=0;j<sz;j++)
		{
			if(i!=j)
			{
				for(int k=0;k<sz;k++)
				{
					if(i!=k && j!=k)
					{
						//print(vec[i].distance(vec[j])<<' '<<vec[i].distance(vec[k])<<' '<<vec[j].distance(vec[k]));
						//print(vec[k].distance(vec[i])<<' '<<vec[k].distance(array[j])<<' '<<vec[i].distance(vec[j]));
						if( vec[i].distance(vec[j])+vec[i].distance(vec[k])==vec[j].distance(vec[k]) ||
							vec[j].distance(vec[i])+vec[j].distance(vec[k])==vec[k].distance(vec[i]) ||
							vec[k].distance(vec[i])+vec[k].distance(vec[j])==vec[i].distance(vec[j]) )
						{
							num++;
						}
					}
				}
			}
		}
	}
	//print(num);
	if(num==24 && st.size()==2) return true;
	else return false;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int a,b;
	for(int i=0;i<SIZE;i++)
	{
		input(a>>b);
		array[i].setpoint(a,b);
	}
	
	vector<cpoint> eins;
	vector<cpoint> zwei;
	int i;
	bool flag=false;
	for(i=0;i<(1<<SIZE);i++)
	{
		int num=0;
		for(int j=0;j<SIZE;j++)
		{
			if(i&(1<<j)) num++;
		}
		if(num!=4) continue;
		
		eins.clear();
		zwei.clear();
		for(int j=0;j<SIZE;j++)
		{
			if(i&(1<<j)) eins.push_back(array[j]);
			else zwei.push_back(array[j]);
		}
		
		//for(int i=0;i<4;i++) printf("%d %d\n",eins[i].x,eins[i].y);
		if(checkS(eins))
		{
			//print("EINS");
			if(checkR(zwei))
			{
				flag=true;
				//print("ZWEI");
				break;
			}
		}
	}
	if(!flag) print("NO");
	else
	{
		flag=true;
		print("YES");
		for(int j=0;j<SIZE;j++)
		{
			if(i & (1<<j))
			{
				if(flag)
				{
					printf("%d",j+1);
					flag=false;
				}
				else printf(" %d",j+1);
			}
		}
		flag=true;
		printf("\n");
		for(int j=0;j<SIZE;j++)
		{
			if( !(i & (1<<j)))
			{
				if(flag)
				{
					printf("%d",j+1);
					flag=false;
				}
				else printf(" %d",j+1);
			}
		}
		print("");
	}
	return 0;
}
