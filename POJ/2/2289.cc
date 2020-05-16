//Result:wizmann	2289	Accepted	3692K	250MS	G++	1256B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define pb push_back

using namespace std;

int n,m;
vector<int> g[1010];
char visit[1010];
int num[1010];
int match[1010][505];

bool hungary(int pos,int val)
{
	for(int i=0;i<(int)g[pos].size();i++)
	{
		int t=g[pos][i];
		if(!visit[t])
		{
			visit[t]=1;
			if(num[t]<val)
			{
				match[t][++num[t]]=pos;
				return true;
			}

			for(int j=1;j<=val;j++)
			{
				if(hungary(match[t][j],val))
				{
					match[t][j]=pos;
					return true;
				}
			}
		}
	}
	return false;
}
			

int main()
{
	freopen("input.txt","r",stdin);
	char str[30];
	int a;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(m==0) break;
		for(int i=0;i<n;i++) g[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			char c=getchar();
			while(c!='\n')
			{
				scanf("%d",&a);
				g[i].pb(a);
				c=getchar();
			}
		}
		
		int l=0,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			memset(match,-1,sizeof(match));
			memset(num,0,sizeof(num));
			bool flag=true;
			for(int i=0;i<n;i++)
			{
				memset(visit,0,sizeof(visit));
				flag=hungary(i,mid);
				if(!flag) break;
			}
			if(flag) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}

////

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

typedef long long llint;

const int SIZE = 1111;

vector<string> split_string(const string& line, char delim) {
    std::istringstream stream(line);
    string token;
    vector<string> res;
    while (std::getline(stream, token, delim)) {
        res.push_back(token);
    }
    return res;
}

class MultiHungary {
public:
    MultiHungary(int left_, int right_) : left(left_), right(right_) {
        g = vector<vector<int> >(left);
        for (int i = 0; i < left; i++) {
            g[i] = vector<int>(right, 0);
        }
        caps = vector<int>(right, 0);
    }

    void setCapacity(int idx, int cap) {
        caps[idx] = cap;
    }

    void addEdge(int l, int r) {
        g[l][r] = 1;
    }
    

    // `all_match` indicates if all nodes on the left 
    // are matched with one of the right nodes
    int match(bool& match_all_left, bool must_match_all_left) {
        int res = 0;
        match_all_left = true;
        pre = vector<vector<int> >(right);
        for (int i = 0; i < left; i++) {
            visited = vector<bool>(right, false);
            if (find_path(i)) {
                res++;
            } else {
                match_all_left = false;
            }

            if (must_match_all_left && !match_all_left) {
                return -1;
            }
        }

        return res;
    }
private:
    bool find_path(int cur) {
        for (int i = 0; i < right; i++) {
            if (g[cur][i] && !visited[i]) {
                visited[i] = true;
                if (pre[i].size() < caps[i]) {
                    pre[i].push_back(cur);
                    return true;
                }
                for (int j = 0; j < pre[i].size(); j++) {
                    int& p = pre[i][j];
                    if (find_path(p)) {
                        p = cur;
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    int left, right;
    vector<vector<int> > g;
    vector<int> caps;
    vector<vector<int> > pre;
    vector<bool> visited;
};

char buffer[2048];

int main() {
    int n, m;

    while (scanf("%d%d\n", &n, &m) != EOF) {
        if (n + m == 0) {
            break;
        }

        MultiHungary mh(n, m);

        for (int i = 0; i < n; i++) {
            fgets(buffer, 2048, stdin);
            string line(buffer);
            // puts(line.c_str());
            vector<string> tokens = split_string(line, ' ');
            int tn = tokens.size();
            for (int j = 1; j < tn; j++) {
                int g = atoi(tokens[j].c_str());
                mh.addEdge(i, g);
            }
        }

        // binary search
        int l = 1;
        int r = n;
        while (l <= r) {
            int mid = (l + r) / 2;

            for (int i = 0; i < m; i++) {
                mh.setCapacity(i, mid);
            }

            bool match_all_left = true;
            mh.match(match_all_left, true);
            if (match_all_left) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}

