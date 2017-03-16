#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1234 * 2;

class Solution {
public:
    Solution(int n_): n(n_) {
        // pass
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
    }

    int hungary()
    {
        int sum=0;
        memset(pre,-1,sizeof(pre));
        
        for(int i=0;i<n;i++)
        {
            memset(match,-1,sizeof(match));
            if(deal(i))
            {
                sum++;
            }
        }
        return sum;
    }
private:
    int n;
    vector<int> g[SIZE];
    int pre[SIZE],match[SIZE];

    bool deal(int nr)
    {
        for(int i=0;i<(int)g[nr].size();i++)
        {
            int next=g[nr][i];
            if(match[next] == -1)
            {
                match[next]=true;
                if(pre[next] == -1 || deal(pre[next]))
                {
                    pre[next]=nr;
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int T;
    int n;

    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        input(n);

        vector<pair<int, int> > topics;

        int idx = 0;
        int left = 0;
        map<string, int> mp;

        string sa, sb;
        for (int i = 0; i < n; i++) {
            input(sa >> sb);

            sa += "____LEFT";
            sb += "____RIGHT";

            if (mp.count(sa) == 0) {
                mp[sa] = idx++;
                left++;
            }

            if (mp.count(sb) == 0) {
                mp[sb] = idx++;
            }

            topics.push_back({mp[sa], mp[sb]});
        }

        Solution* S = new Solution(idx);

        for (auto p: topics) {
            // print(p.first << ' ' << p.second << ' ' << idx);
            S->addEdge(p.first, p.second);
        }

        // print(n << ' ' << idx << ' ' << S->hungary());
        printf("Case #%d: ", case_ + 1);
        print(n - idx + S->hungary());
        delete S;
    }
    return 0;
}

