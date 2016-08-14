#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (decltype(n) i = 0; i < n; i++)

const int SIZE = 222;

int idx = 1;
unordered_map<string, int> mp;
vector<int> passions[SIZE];
vector<int> g[SIZE];

int n;
int pre[SIZE],match[SIZE];
vector<int> ans;
unordered_map<int, int> ticket;

bool deal(int nr)
{
	for(int i=0;i<(int)g[nr].size();i++)
	{
		int next=g[nr][i];
		if(!match[next])
		{
			match[next]=true;
			if(!pre[next] || deal(pre[next]))
			{
				pre[next]=nr;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int sum=0;
	memset(pre,0,sizeof(pre));
	
	for(int i=1;i<=n;i++)
	{
		memset(match,0,sizeof(match));
		if(deal(i))
		{
			sum++;
			ans.push_back(i);
		}
	}
	return sum;
}


int main() {
    input(n);
    int a, b;
    string s;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        ticket[a]++;
        loop(j, b) {
            input(s);
            if (mp.find(s) == mp.end()) {
                mp[s] = idx++;
            }
            passions[i].push_back(mp[s]);
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        unordered_set<int> st;
        loop(j, a) {
            input(s);
            if (mp.find(s) == mp.end()) {
                continue;
            }
            st.insert(mp[s]);
        }
        if (ticket[i] == 0) {
            continue;
        }
        for (int k = 1; k <= n; k++) {
            for (const auto& p: passions[k]) {
                if (st.find(p) != st.end()) {
                    g[k].push_back(i);
                    // print(k << ' ' << i);
                    break;
                }
            }
        }
    }
    print(hungary());
    return 0;
}
