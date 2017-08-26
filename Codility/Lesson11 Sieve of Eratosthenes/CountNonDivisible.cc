// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <map>

const int SIZE = 100010;

vector<int> solution(vector<int> &A) {
    map<int, int> mp;
    for (auto item: A) {
        mp[item]++;
    }
    
    vector<int> sieve(SIZE, A.size());
    
    for (auto p: mp) {
        for (int j = 1; p.first * j < SIZE; j++) {
            sieve[p.first * j] -= p.second;
        }
    }
    
    vector<int> res;
    for (auto item: A) {
        res.push_back(sieve[item]);
    }
    return res;
}
