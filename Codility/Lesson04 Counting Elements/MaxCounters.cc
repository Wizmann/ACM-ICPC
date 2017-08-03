// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <map>

vector<int> solution(int n, vector<int> &A) {
    map<int, int> mp;
    int base = 0;
    
    for (auto q: A) {
        if (q > n) {
            int maxi = 0;
            for (auto p: mp) {
                maxi = max(maxi, p.second);
            }
            base += maxi;
            mp.clear();
        } else {
            mp[q]++;
        }
    }
    
    vector<int> res(n, base);
    for (auto p: mp) {
        res[p.first - 1] += p.second;
    }
    
    return res;
}
