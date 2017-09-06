#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

template<typename T>
class FuzzyMap {
public:
    FuzzyMap() {
        // pass
    }
    
    template<typename iterT>
    FuzzyMap(iterT st, iterT end) {
        for (auto iter = st; iter != end; ++iter) {
            add_value(*iter, +1);
        }
    }

    void set_value(const T& t, int value) {
        mp[t] = value;
        pq.push({value, t});
    }
    
    void add_value(const T& t, int delta) {
        mp[t] += delta;
        pq.push({mp[t], t});
    }
    
    int get_value(const T& t) {
        return mp[t];
    }
    
    int get_max(T& t, int& value) {
        while (!pq.empty()) {
            const auto& cur = pq.top();

            const int& cnt = cur.first;
            const T& item = cur.second;
            
            if (mp[item] != cnt) {
                pq.pop();
            } else {
                t = item;
                value = cnt;
                return 0;
            }
        }
        return -1;
    }
private:
    map<T, int> mp;
    priority_queue<pair<int, T> > pq;
};

FuzzyMap<char> mp;

bool check(char c, int l, int n) {
    mp.add_value(c, -1);
    
    char tmp = '\0';
    int maxi = 0;
    mp.get_max(tmp, maxi);
    
    mp.add_value(c, +1);
    
    return maxi * 2 <= n - l + 1;
}

string solve(const string& s) {
    string res = "";
    
    mp = FuzzyMap<char>(s.begin(), s.end());
    
    int n = s.size();
    char pre = '\0';
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c == pre) {
                continue;
            }
            
            if (mp.get_value(c) == 0) {
                continue;
            }
            
            if (check(c, i + 1, n)) {
                res += c;
                mp.add_value(c, -1);
                flag = true;
                pre = c;
                break;
            }
        }
        // print(res);
        if (!flag) {
            return "INVALID";
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    input(s);
    
    print(solve(s));
    
    return 0;
}
