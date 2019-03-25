// HDU 2896
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

template <int ALPHABET, int NODE_SIZE>
class ACAutomation {
public:
    void insert(const string& str, int nr) {
        int p = ROOT;
        for (int i = 0; i < str.size(); i++) {
            int c = str[i];
            if (!trie[p].next[c]) {
                trie[p].next[c] = ++tail;
            }
            p=trie[p].next[c];
        }
        trie[p].frq++;
        trie[p].end=nr;
    }

    void makeAC() {
        queue<int> q;
        for (int i = 0; i < ALPHABET; i++) {
            if (trie[ROOT].next[i]) {
                trie[trie[ROOT].next[i]].fail = ROOT;
                q.push(trie[ROOT].next[i]);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i=0; i < ALPHABET; i++) {
                if (trie[p].next[i]) {
                    int v = trie[p].next[i];
                    q.push(v);
                    trie[v].fail = trie[trie[p].fail].next[i];
                } else {
                    trie[p].next[i] = trie[trie[p].fail].next[i];
                }
            }
        }
    }

    int find(int p, char c, vector<int>& matched) {
        while (trie[p].fail && !trie[p].next[c]) {
            p = trie[p].fail;
        }
            
        p = trie[p].next[c];
        int t = p;
        while (t) {
            if (trie[t].end) {
                matched.push_back(trie[t].end);
            }
            t = trie[t].fail;
        }
        return p;
    }

    void clear() {
        memset(trie, 0, sizeof(trie));
        tail = 0;
    }
private:
    struct node {
        int next[ALPHABET];
        int fail;
        int frq;
        int end; 
    };

    int tail = 0;
    node trie[NODE_SIZE];
public:
    const int ROOT = 0;
};

int n, m;
ACAutomation<128, 30000> ac;
char word[12345];

int main()
{
    long long ans=0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", word);
        ac.insert(word, i);
    }

    ac.makeAC(); // <- ** DO NOT FORGET THIS **

    scanf("%d",&m);
    for(int i = 1;i <= m; i++) {
        scanf("%s", word);
        vector<int> matched;
        int p = ac.ROOT;
        for (int j = 0; word[j]; j++) {
            p = ac.find(p, word[j], matched);
        }

        sort(matched.begin(), matched.end());
        if (!matched.empty())
        {
            ans++;
            printf("web %d: ",i);
            for (int j = 0; j < matched.size(); j++) {
                if (j) {
                    printf(" ");
                }
                printf("%d", matched[j]);
            }
            puts("");
        }
    }
    printf("total: %lld\n",ans);
    return 0;
}
