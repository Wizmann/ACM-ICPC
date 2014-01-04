// Result : 10905   Children's Game Accepted    C++ 0.275   2013-12-22 06:25:39
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int n;
vector<string> vec;

bool cmp_num(const string& a, const string& b)
{
    return a + b > b + a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string t;
    while (input(n) && n) {
        vec.clear();
        for (int i = 0; i < n; i++) {
            input(t);
            vec.push_back(t);
        }
        sort(vec.begin(), vec.end(), cmp_num);

        t = "";
        for (int i = 0; i < (int)vec.size(); i++) {
            t += vec[i];
        }
        print(t);
    }
    return 0;
}




