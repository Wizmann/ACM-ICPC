#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <map>
#include <iostream>

using namespace std;

class DisjointSet {
public:
    DisjointSet(int n_) : n(n_), father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        father[fb] = fa;
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
private:
    int n;
    vector<int> father;
};



bool solution(vector<int> &P, vector<int> &T, vector<int> &A, vector<int> &B) {
    const int n = P.size();
    assert(P.size() == n && T.size() == n);
    DisjointSet ds(n);

    const int m = A.size();
    assert(A.size() == m && B.size() == m);

    for (int i = 0; i < m; i++) {
        int a = A[i];
        int b = B[i];
        ds.make_union(a, b);
    }

    map<int, int> toy_mp[3];
    map<int, int> pet_mp[3];
    vector<int> fathers;
    for (int i = 0; i < n; i++) {
        int f = ds.find_father(i);
        fathers.push_back(f);
        toy_mp[P[i]][f]++;
        pet_mp[T[i]][f]++;
    }

    for (auto f : fathers) {
        for (int i = 1; i <= 2; i++) {
            if (toy_mp[i][f] != pet_mp[i][f]) {
                return false;
            }
        }
    }
    return true;
}

